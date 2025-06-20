// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "CalculateCastTime.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCastTimeDataSignature, const float&, Data);

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API UCalculateCastTime : public UAbilityTask
{
	GENERATED_BODY()


public:

	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (DisplayName = "CalculateCastTime", HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternUseOnly = "true"))
	static UCalculateCastTime* UpdateCastTime(UGameplayAbility* OwningAbility);

	UPROPERTY(BlueprintAssignable)
	FCastTimeDataSignature ValidData;

private:

	virtual void Activate() override;

};
