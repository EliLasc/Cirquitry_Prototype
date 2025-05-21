// Copyright Cirquitry


#include "Character/Cirquitry_PlayerCharacter.h"

#include "AbilitySystem/Cirquitry_AttributeSet.h"
#include "Character/Cirquitry_EnemyCharacter.h"
#include "Game/Cirquitry_GameInstance.h"
#include "Player/Cirquitry_PlayerController.h"
#include "Player/Cirquitry_PlayerState.h"
#include "UI/HUD/Cirquitry_HUD.h"

ACirquitry_PlayerCharacter::ACirquitry_PlayerCharacter()
{
	
}

void ACirquitry_PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();
}

void ACirquitry_PlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}


void ACirquitry_PlayerCharacter::InitAbilityActorInfo()
{
	ACirquitry_PlayerState* Cirquitry_PlayerState = GetPlayerState<ACirquitry_PlayerState>();
	check(Cirquitry_PlayerState);
	Cirquitry_PlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(Cirquitry_PlayerState, this);

	UCirquitry_GameInstance* GameInstance = Cast<UCirquitry_GameInstance>(GetGameInstance());
	GameInstance->SpawnManagers();
	
	Cirquitry_PlayerState->SpawnEnemy();
	ACirquitry_EnemyCharacter* EnemyCharacter = Cirquitry_PlayerState->GetEnemyCharacter();
	TObjectPtr<UAttributeSet> EnemyAttributeSet = EnemyCharacter->GetAttributeSet();
	
	AbilitySystemComponent = Cirquitry_PlayerState->GetAbilitySystemComponent();
	AttributeSet = Cirquitry_PlayerState->GetAttributeSet();

	if (ACirquitry_PlayerController* Cirquitry_PlayerController = Cast<ACirquitry_PlayerController>(GetController()))
	{
		if(ACirquitry_HUD* Cirquitry_HUD = Cast<ACirquitry_HUD>(Cirquitry_PlayerController->GetHUD()))
		{
			Cirquitry_HUD->InitOverlay(Cirquitry_PlayerController, Cirquitry_PlayerState, AbilitySystemComponent, AttributeSet, EnemyAttributeSet);
		}
	}
	
}
