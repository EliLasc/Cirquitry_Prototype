// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "Character/Cirquitry_CharacterBase.h"
#include "Manager/Cirquitry_GameplayManager.h"
#include "Cirquitry_EnemyCharacter.h"
#include "Cirquitry_PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_PlayerCharacter : public ACirquitry_CharacterBase
{
	GENERATED_BODY()

public:
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Manager")
	TSubclassOf<ACirquitry_GameplayManager> GameplayManagerClass;

	UPROPERTY()
	AActor* GameplayManager;

private:
	virtual void InitAbilityActorInfo() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "EnemyCharacter")
	TSubclassOf<ACirquitry_EnemyCharacter> EnemyCharacterClass;
};
