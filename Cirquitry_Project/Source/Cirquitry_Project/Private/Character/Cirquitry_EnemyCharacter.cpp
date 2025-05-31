// Copyright Cirquitry


#include "Character/Cirquitry_EnemyCharacter.h"

#include "AbilitySystem/Cirquitry_AbilitySystemComponent.h"
#include "AbilitySystem/Cirquitry_AttributeSet.h"

ACirquitry_EnemyCharacter::ACirquitry_EnemyCharacter()
{
	//the following is here since enemies won't have a "player state" to contain these variables
	AbilitySystemComponent = CreateDefaultSubobject<UCirquitry_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UCirquitry_AttributeSet>("AttributeSet");
}

void ACirquitry_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
	InitializeCombatAttributes();
}

void ACirquitry_EnemyCharacter::InitAbilityActorInfo()
{
	//since no player state, the owning actor is instead the character actor itself
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UCirquitry_AbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}
