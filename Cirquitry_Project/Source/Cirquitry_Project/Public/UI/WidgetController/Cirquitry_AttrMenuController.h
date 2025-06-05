// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/Cirquitry_WidgetController.h"
#include "Cirquitry_AttrMenuController.generated.h"

class UCirquitry_AttributeInfo;
struct FCirquitryAttributeInfo;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeInfoSignature, const FCirquitryAttributeInfo&, Info);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CIRQUITRY_PROJECT_API UCirquitry_AttrMenuController : public UCirquitry_WidgetController
{
	GENERATED_BODY()
public:
	virtual void BindCallBacksToDependencies() override;
	virtual void BroadcastInitialValues() override;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FAttributeInfoSignature AttributeInfoDelegate;

protected:

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCirquitry_AttributeInfo> PlayerAttributeInfo;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCirquitry_AttributeInfo> EnemyAttributeInfo;
};

