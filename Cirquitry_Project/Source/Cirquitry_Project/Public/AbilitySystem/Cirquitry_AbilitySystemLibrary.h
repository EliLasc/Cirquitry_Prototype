// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Cirquitry_AbilitySystemLibrary.generated.h"


class UCirquitry_AttrMenuController;
class UCirquitry_OverWidgetController;
/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API UCirquitry_AbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintPure, Category = "CirquitryAbilitySystemLibrary|WidgetController")
	static UCirquitry_OverWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "CirquitryAbilitySystemLibrary|WidgetController")
	static UCirquitry_AttrMenuController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);
};
