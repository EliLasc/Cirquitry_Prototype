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
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCirquitry_CirquitryManager> CirquitryManager;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UCirquitry_SpellcastingManager> SpellCastingManager;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UCirquitry_CombatManager> CombatManager;
};
