// Copyright Cirquitry


#include "UI/Widget/Cirquitry_UserWidget.h"

void UCirquitry_UserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
