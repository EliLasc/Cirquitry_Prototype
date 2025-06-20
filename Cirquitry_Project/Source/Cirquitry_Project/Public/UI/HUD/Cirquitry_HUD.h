// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Cirquitry_HUD.generated.h"

class UCirquitry_AttrMenuController;
class UAttributeSet;
class UAbilitySystemComponent;
class UCirquitry_OverWidgetController;
class UCirquitry_UserWidget;

struct FWidgetControllerParams;
/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_HUD : public AHUD
{
	GENERATED_BODY()

public:
	UCirquitry_OverWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	UCirquitry_AttrMenuController* GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams);
	
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* PASC, UAbilitySystemComponent* EASC, UAttributeSet* PAS, UAttributeSet* EAS);
	
protected:
	
private:

	UPROPERTY()
	TObjectPtr<UCirquitry_UserWidget> OverlayWidget;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UCirquitry_UserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UCirquitry_OverWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCirquitry_OverWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
	TObjectPtr<UCirquitry_AttrMenuController> AttributeMenuWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCirquitry_AttrMenuController> AttributeMenuWidgetControllerClass;
};
