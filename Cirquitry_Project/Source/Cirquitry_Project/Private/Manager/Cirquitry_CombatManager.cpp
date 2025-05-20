// Copyright Cirquitry


#include "Manager/Cirquitry_CombatManager.h"
#include "AbilitySystem/Cirquitry_AbilitySystemComponent.h"

ACirquitry_CombatManager::ACirquitry_CombatManager()
{
	PrimaryActorTick.bCanEverTick = false;
	
	AbilitySystemComponent = CreateDefaultSubobject<UCirquitry_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}


