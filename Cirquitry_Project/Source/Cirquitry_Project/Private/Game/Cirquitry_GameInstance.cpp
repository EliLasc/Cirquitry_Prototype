// Copyright Cirquitry


#include "Game/Cirquitry_GameInstance.h"

UCirquitry_GameInstance::UCirquitry_GameInstance()
{
	
}

void UCirquitry_GameInstance::SpawnManagers()
{
	CirquitryManager = GetWorld()->SpawnActor<ACirquitry_CirquitryManager>(CirquitryManagerClass, FVector(0,0,0), FRotator(0,0,0));
	SpellCastingManager = GetWorld()->SpawnActor<ACirquitry_SpellcastingManager>(SpellCastingManagerClass, FVector(0,0,0), FRotator(0,0,0));
	CombatManager = GetWorld()->SpawnActor<ACirquitry_CombatManager>(CombatManagerClass, FVector(0,0,0), FRotator(0,0,0));
}
