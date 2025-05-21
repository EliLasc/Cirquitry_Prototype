// Copyright Cirquitry


#include "Player/Cirquitry_PlayerState.h"

#include "AbilitySystem/Cirquitry_AbilitySystemComponent.h"
#include "AbilitySystem/Cirquitry_AttributeSet.h"

ACirquitry_PlayerState::ACirquitry_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UCirquitry_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UCirquitry_AttributeSet>("AttributeSet");
	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* ACirquitry_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ACirquitry_PlayerState::SpawnEnemy()
{
	UE_LOG(LogTemp, Warning, TEXT("Spawned Enemy"));
	EnemyCharacter = GetWorld()->SpawnActor<ACirquitry_EnemyCharacter>(EnemyCharacterClass, FVector(0,0,0), FRotator(0,0,0));
}
