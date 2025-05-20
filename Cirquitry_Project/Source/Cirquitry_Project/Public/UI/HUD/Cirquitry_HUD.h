// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/Widget/Cirquitry_UserWidget.h"
#include "Cirquitry_HUD.generated.h"

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_HUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<UCirquitry_UserWidget> OverlayWidget;

protected:
	virtual void BeginPlay() override;
	
private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCirquitry_UserWidget> OverlayWidgetClass;
};
