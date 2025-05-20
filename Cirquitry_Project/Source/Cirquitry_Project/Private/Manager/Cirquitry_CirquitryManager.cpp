// Copyright Cirquitry


#include "Manager/Cirquitry_CirquitryManager.h"
#include "AbilitySystem/Cirquitry_AbilitySystemComponent.h"

ACirquitry_CirquitryManager::ACirquitry_CirquitryManager()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UCirquitry_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

