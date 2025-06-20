// Copyright Cirquitry


#include "Character/Cirquitry_CharacterBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/Cirquitry_AbilitySystemComponent.h"

ACirquitry_CharacterBase::ACirquitry_CharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

UAbilitySystemComponent* ACirquitry_CharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ACirquitry_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACirquitry_CharacterBase::InitAbilityActorInfo()
{
	
}

void ACirquitry_CharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Round) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void ACirquitry_CharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPreCombatAttributes, 1.f);
	ApplyEffectToSelf(DefaultCombatAttributes, 1.f);
}

void ACirquitry_CharacterBase::AddCharacterAbilities()
{
	UCirquitry_AbilitySystemComponent* CirquitryASC = CastChecked<UCirquitry_AbilitySystemComponent>(AbilitySystemComponent);
	if (!HasAuthority()) return;

	CirquitryASC->AddCharacterAbilities(StartupAbilities);
}


