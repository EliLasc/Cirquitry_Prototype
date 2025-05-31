// Copyright Cirquitry


#include "Character/Cirquitry_CharacterBase.h"
#include "AbilitySystemComponent.h"

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

void ACirquitry_CharacterBase::InitializePreCombatAttributes() const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(DefaultPreCombatAttributes);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultPreCombatAttributes, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void ACirquitry_CharacterBase::InitializeCombatAttributes() const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(DefaultCombatAttributes);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultCombatAttributes, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}


