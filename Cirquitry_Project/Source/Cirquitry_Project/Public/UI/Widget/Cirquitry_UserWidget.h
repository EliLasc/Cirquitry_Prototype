// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Cirquitry_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API UCirquitry_UserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
