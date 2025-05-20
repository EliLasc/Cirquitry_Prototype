// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Cirquitry_WidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;


/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API UCirquitry_WidgetController : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;
};
