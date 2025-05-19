// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Cirquitry_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ACirquitry_PlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> CirquitryContext;

	//This is an example of how to add a variable to assign as an Input Action
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> PauseMenu;
	
};
