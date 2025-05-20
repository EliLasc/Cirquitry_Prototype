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

UAbilitySystemComponent* ACirquitry_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;

}

void ACirquitry_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
