// Copyright Cirquitry


#include "Character/Cirquitry_PlayerCharacter.h"
#include "Character/Cirquitry_EnemyCharacter.h"
#include "Player/Cirquitry_PlayerController.h"
#include "Player/Cirquitry_PlayerState.h"
#include "UI/HUD/Cirquitry_HUD.h"
#include "AbilitySystem/Cirquitry_AbilitySystemComponent.h"
#include "AbilitySystem/Cirquitry_AttributeSet.h"
#include "Kismet/GameplayStatics.h"

void ACirquitry_PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();
}

void ACirquitry_PlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}

int32 ACirquitry_PlayerCharacter::GetRound()
{
	const ACirquitry_PlayerState* Cirquitry_PlayerState = GetPlayerState<ACirquitry_PlayerState>();
	check(Cirquitry_PlayerState);
	return Cirquitry_PlayerState->GetRound();
}

void ACirquitry_PlayerCharacter::InitAbilityActorInfo()
{
	ACirquitry_PlayerState* Cirquitry_PlayerState = GetPlayerState<ACirquitry_PlayerState>();
	check(Cirquitry_PlayerState);
	Cirquitry_PlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(Cirquitry_PlayerState, this);
	Cast<UCirquitry_AbilitySystemComponent>(Cirquitry_PlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();

	//The enemy character script initializes its own variables upon spawn
	ACirquitry_EnemyCharacter* EnemyCharacter = GetWorld()->SpawnActor<ACirquitry_EnemyCharacter>(EnemyCharacterClass, FVector(0,0,0), FRotator(0,0,0));
	TObjectPtr<UAttributeSet> EnemyAttributeSet = EnemyCharacter->GetAttributeSet();
	TObjectPtr<UAbilitySystemComponent> EnemyAbilitySystemComponent = EnemyCharacter->GetAbilitySystemComponent();

	Cirquitry_PlayerState->SetEnemyGAS(EnemyAbilitySystemComponent, EnemyAttributeSet);
	
	AbilitySystemComponent = Cirquitry_PlayerState->GetAbilitySystemComponent();
	AttributeSet = Cirquitry_PlayerState->GetAttributeSet();

	if (ACirquitry_PlayerController* Cirquitry_PlayerController = Cast<ACirquitry_PlayerController>(GetController()))
	{
		if(ACirquitry_HUD* Cirquitry_HUD = Cast<ACirquitry_HUD>(Cirquitry_PlayerController->GetHUD()))
		{
			Cirquitry_HUD->InitOverlay(Cirquitry_PlayerController, Cirquitry_PlayerState, AbilitySystemComponent, EnemyAbilitySystemComponent, AttributeSet, EnemyAttributeSet);
		}
	}

	InitializeDefaultAttributes();
	
	GameplayManager = UGameplayStatics::BeginDeferredActorSpawnFromClass(GetWorld(), GameplayManagerClass, FTransform::Identity);
	if(GameplayManager)
	{
		ACirquitry_GameplayManager* CustomGameplayManager = Cast<ACirquitry_GameplayManager>(GameplayManager);
		CustomGameplayManager->SetSpawnVariables(this, EnemyCharacter);
		UGameplayStatics::FinishSpawningActor(GameplayManager, FTransform::Identity);
	}
}

	

