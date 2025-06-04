// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/Cirquitry_WidgetController.h"
#include "Cirquitry_AttrMenuController.generated.h"

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API UCirquitry_AttrMenuController : public UCirquitry_WidgetController
{
	GENERATED_BODY()
public:
	virtual void BindCallBacksToDependencies() override;
	virtual void BroadcastInitialValues() override;
};
