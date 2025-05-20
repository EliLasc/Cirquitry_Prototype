// Copyright Cirquitry


#include "AbilitySystem/Cirquitry_AttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"
//#include "Cirquitry_GameplayTags.h"


UCirquitry_AttributeSet::UCirquitry_AttributeSet()
{
	//const FCirquitry_GameplayTags& GameplayTags = FCirquitry_GameplayTags::Get();
	
	/* Primary Attributes */
	//TagsToAttributes.Add(GameplayTags.Attributes_Primary_Strength, GetStrengthAttribute);

	/* Secondary Attributes */
	//TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Armor, GetArmorAttribute);
}

void UCirquitry_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	/*
	 * Vital Attributes
	 */

	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, Health, COND_None, REPNOTIFY_Always)

	/*
	 * Primary Attributes
	 */

	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, Strength, COND_None, REPNOTIFY_Always);

	/*
	 * Secondary Attributes
	 */

	DOREPLIFETIME_CONDITION_NOTIFY(UCirquitry_AttributeSet, Armor, COND_None, REPNOTIFY_Always);
}

void UCirquitry_AttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if(Attribute == GetHealthAttribute())
	{
		//NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
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
			{
				Props.SourceController = Pawn->GetController();
			}
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

	//Since the clamp in PreGameplayEffectExecute only sets the displayed value, the post GameplayEffect will then set the value
	if(Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		//SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
	//if(Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		//SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}
}

/*
 * Vital Attributes
 */

void UCirquitry_AttributeSet::OnRep_Health(const FGameplayAttributeData OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, Health, OldHealth);
}

/*
 * Primary Attributes
 */

void UCirquitry_AttributeSet::OnRep_Strength(const FGameplayAttributeData OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, Strength, OldStrength);
}

/*
 * Secondary Attributes
 */

void UCirquitry_AttributeSet::OnRep_Armor(const FGameplayAttributeData OldArmor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCirquitry_AttributeSet, Armor, OldArmor);
}

