// Copyright Cirquitry


#include "UI/HUD/Cirquitry_HUD.h"
#include "UI/Widget/Cirquitry_UserWidget.h"
#include "UI/WidgetController/Cirquitry_OverWidgetController.h"

UCirquitry_OverWidgetController* ACirquitry_HUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UCirquitry_OverWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallBacksToDependencies();
		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void ACirquitry_HUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* PASC, UAbilitySystemComponent* EASC, UAttributeSet* PAS, UAttributeSet* EAS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_AuraHUD"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UCirquitry_UserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, PASC, EASC, PAS, EAS);
	UCirquitry_OverWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	
	Widget->AddToViewport();
}

