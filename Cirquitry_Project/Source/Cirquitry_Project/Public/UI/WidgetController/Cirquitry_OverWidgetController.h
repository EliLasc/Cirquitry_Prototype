// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/Cirquitry_WidgetController.h"
#include "Game/Cirquitry_GameInstance.h"
#include "Cirquitry_OverWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CIRQUITRY_PROJECT_API UCirquitry_OverWidgetController : public UCirquitry_WidgetController
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallBacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;

protected:
	void HealthChanged(const FOnAttributeChangeData& Data) const;

	UPROPERTY()
	TObjectPtr<UCirquitry_GameInstance> GameInstance;

};
