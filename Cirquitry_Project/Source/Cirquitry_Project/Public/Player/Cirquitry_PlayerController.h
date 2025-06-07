// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "Cirquitry_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class UCirquitry_InputConfig;
class UCirquitry_AbilitySystemComponent;

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

	//void Pause(const FInputActionValue& InputActionValue);
	
	//This is an example of how to add a variable to assign as an Input Action
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> PauseMenu;
	
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UCirquitry_InputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UCirquitry_AbilitySystemComponent> Cirquitry_AbilitySystemComponent;

	UCirquitry_AbilitySystemComponent* GetASC();
};
