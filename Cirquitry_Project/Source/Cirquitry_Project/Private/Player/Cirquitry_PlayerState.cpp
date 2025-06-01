// Copyright Cirquitry


#include "Player/Cirquitry_PlayerState.h"

#include "AbilitySystem/Cirquitry_AbilitySystemComponent.h"
#include "AbilitySystem/Cirquitry_AttributeSet.h"
#include "Net/UnrealNetwork.h"

ACirquitry_PlayerState::ACirquitry_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UCirquitry_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UCirquitry_AttributeSet>("AttributeSet");
	SetNetUpdateFrequency(100.f);
}

void ACirquitry_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACirquitry_PlayerState, Round);
}

UAbilitySystemComponent* ACirquitry_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ACirquitry_PlayerState::OnRep_Round(int32 OldRound)
{
	
}
