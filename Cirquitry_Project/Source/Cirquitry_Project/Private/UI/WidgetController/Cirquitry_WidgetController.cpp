// Copyright Cirquitry


#include "UI/WidgetController/Cirquitry_WidgetController.h"

void UCirquitry_WidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.PlayerAttributeSet;
}

void UCirquitry_WidgetController::BroadcastInitialValues()
{
	
}

void UCirquitry_WidgetController::BindCallBacksToDependencies()
{
	
}
