// Copyright Cirquitry


#include "AbilitySystem/Cirquitry_AttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"
#include "Cirquitry_GameplayTags.h"


UCirquitry_AttributeSet::UCirquitry_AttributeSet()
{
	const FCirquitryGameplayTags& GameplayTags = FCirquitryGameplayTags::Get();

	/* CombatAttributes */
	TagsToAttributes.Add(GameplayTags.Attributes_Combat_MaxHealth, GetMaxHealthAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Combat_Health, GetHealthAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Combat_BaseCircleMana, GetBaseCircleManaAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Combat_BaseManaShield, GetBaseManaShieldAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Combat_ManaShield, GetManaShieldAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Combat_DamageResistance, GetDamageResistanceAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Combat_CastSpeed, GetCastSpeedAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Combat_CritChance, GetCritChanceAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Combat_Accuracy, GetAccuracyAttribute);

	/*PreCombat Attributes*/
	TagsToAttributes.Add(GameplayTags.Attributes_PreCombat_SpellCircleCount, GetSpellCircleCountAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_PreCombat_Wealth, GetWealthAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_PreCombat_Luck, GetLuckAttribute);
}

void UCirquitry_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	/*
	 * Combat Attributes
	 */

	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, MaxHealth, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, Health, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, BaseCircleMana, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, BaseManaShield, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, ManaShield, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, DamageResistance, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, CastSpeed, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, CritChance, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, Accuracy, COND_None, REPNOTIFY_Always)

	/*
	 * PreCombat Attributes
	 */

	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, SpellCircleCount, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, Wealth, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, Luck, COND_None, REPNOTIFY_Always)
}

void UCirquitry_AttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	/*
	 * Combat Attributes
	 */

	//Any attributes that are clamped need the max value set first in the gameplay effect
	if(Attribute == GetHealthAttribute())
	{NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());}

	if(Attribute == GetManaShieldAttribute())
	{NewValue = FMath::Clamp(NewValue, 0.f, 10000);}

	/*
	 * PreCombat Attributes
	 */
}

void UCirquitry_AttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{
	//Source = the causer of the effect, Target = target of the effect (owner of this AS)
	
	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
		if(Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if(const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{Props.SourceController = Pawn->GetController();}
		}
		if(Props.SourceController)
		{
			Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}

	if(Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController =  Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
}

void UCirquitry_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;
	SetEffectProperties(Data, Props);

	/*
	 * Combat Attributes
	 */
	
	//Since the clamp in PreGameplayEffectExecute only sets the displayed value, the post GameplayEffect will then set the value
	if(Data.EvaluatedData.Attribute == GetHealthAttribute())
	{SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));}

	if(Data.EvaluatedData.Attribute == GetManaShieldAttribute())
	{SetHealth(FMath::Clamp(GetManaShield(), 0.f, 10000));}

	/*
	 * PreCombat Attributes
	 */
}

/*
 * Combat Attributes
 */

void UCirquitry_AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData OldMaxHealth) const
{GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, MaxHealth, OldMaxHealth);}

void UCirquitry_AttributeSet::OnRep_Health(const FGameplayAttributeData OldHealth) const
{GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, Health, OldHealth);}

void UCirquitry_AttributeSet::OnRep_BaseCircleMana(const FGameplayAttributeData OldBaseCircleMana) const
{GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, BaseCircleMana, OldBaseCircleMana);}

void UCirquitry_AttributeSet::OnRep_BaseManaShield(const FGameplayAttributeData OldBaseManaShield) const
{GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, BaseManaShield, OldBaseManaShield);}

void UCirquitry_AttributeSet::OnRep_ManaShield(const FGameplayAttributeData OldManaShield) const
{GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, ManaShield, OldManaShield);}

void UCirquitry_AttributeSet::OnRep_DamageResistance(const FGameplayAttributeData OldDamageResistance) const
{GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, DamageResistance, OldDamageResistance);}

void UCirquitry_AttributeSet::OnRep_CastSpeed(const FGameplayAttributeData OldCastSpeed) const
{GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, CastSpeed, OldCastSpeed);}

void UCirquitry_AttributeSet::OnRep_CritChance(const FGameplayAttributeData OldCritChance) const
{GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, CritChance, OldCritChance);}

void UCirquitry_AttributeSet::OnRep_Accuracy(const FGameplayAttributeData OldAccuracy) const
{GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, Accuracy, OldAccuracy);}

/*
 * PreCombat Attributes
 */

void UCirquitry_AttributeSet::OnRep_SpellCircleCount(const FGameplayAttributeData OldSpellCircleCount) const
{GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, SpellCircleCount, OldSpellCircleCount);}

void UCirquitry_AttributeSet::OnRep_Wealth(const FGameplayAttributeData OldWealth) const
{GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, Wealth, OldWealth);}

void UCirquitry_AttributeSet::OnRep_Luck(const FGameplayAttributeData OldLuck) const
{GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, Luck, OldLuck);}

