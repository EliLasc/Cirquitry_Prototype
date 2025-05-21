// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Manager/Cirquitry_CirquitryManager.h"
#include "Manager/Cirquitry_CombatManager.h"
#include "Manager/Cirquitry_SpellcastingManager.h"

#include "Cirquitry_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API UCirquitry_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UCirquitry_GameInstance();
	virtual void SpawnManagers();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Manager")
	TSubclassOf<ACirquitry_CirquitryManager> CirquitryManagerClass;

	UPROPERTY()
	AActor* CirquitryManager;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Manager")
	TSubclassOf<ACirquitry_SpellcastingManager> SpellCastingManagerClass;

	UPROPERTY()
	AActor* SpellCastingManager;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Manager")
	TSubclassOf<ACirquitry_CombatManager> CombatManagerClass;

	UPROPERTY()
	AActor* CombatManager;
	
};
