// Copyright Cirquitry


#include "Player/Cirquitry_PlayerState.h"

#include "AbilitySystem/Cirquitry_AbilitySystemComponent.h"
#include "AbilitySystem/Cirquitry_AttributeSet.h"

ACirquitry_PlayerState::ACirquitry_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UCirquitry_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UCirquitry_AttributeSet>("AttributeSet");

	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* ACirquitry_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
