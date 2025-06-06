// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Cirquitry_GameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API UCirquitry_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:

	//checks the ability tags when first generated/given to the character
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	FGameplayTag StartupInputTag;
};
