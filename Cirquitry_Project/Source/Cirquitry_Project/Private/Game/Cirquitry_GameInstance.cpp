// Copyright Cirquitry


#include "Game/Cirquitry_GameInstance.h"

UCirquitry_GameInstance::UCirquitry_GameInstance()
{
	CirquitryManager = CreateDefaultSubobject<UCirquitry_CirquitryManager>("CirquitryManager");
	SpellCastingManager = CreateDefaultSubobject<UCirquitry_SpellcastingManager>("SpellCastingManager");
	CombatManager = CreateDefaultSubobject<UCirquitry_CombatManager>("CombatManager");
}
