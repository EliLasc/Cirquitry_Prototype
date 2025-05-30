// Copyright Cirquitry


#include "UI/WidgetController/Cirquitry_WidgetController.h"

void UCirquitry_WidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	PlayerAbilitySystemComponent = WCParams.PlayerAbilitySystemComponent;
	EnemyAbilitySystemComponent = WCParams.EnemyAbilitySystemComponent;
	PlayerAttributeSet = WCParams.PlayerAttributeSet;
	EnemyAttributeSet = WCParams.EnemyAttributeSet;
}

void UCirquitry_WidgetController::BroadcastInitialValues()
{
	
}

void UCirquitry_WidgetController::BindCallBacksToDependencies()
{
	
}
