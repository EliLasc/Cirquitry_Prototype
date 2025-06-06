// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Cirquitry_InputConfig.generated.h"

USTRUCT(BlueprintType)
struct FCirquitry_InputAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	const class UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag();
};
/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API UCirquitry_InputConfig : public UDataAsset
{
	GENERATED_BODY()

public:

	//Returns the input action associated with a give tag
	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = false) const;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FCirquitry_InputAction> AbilityInputActions;
};
