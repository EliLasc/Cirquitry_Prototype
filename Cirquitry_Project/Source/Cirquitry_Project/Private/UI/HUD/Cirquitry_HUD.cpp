// Copyright Cirquitry


#include "UI/HUD/Cirquitry_HUD.h"
#include "UI/Widget/Cirquitry_UserWidget.h"

void ACirquitry_HUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
