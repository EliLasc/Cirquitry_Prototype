// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "Cirquitry_MMC_CalculateCastTime.generated.h"

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API UCirquitry_MMC_CalculateCastTime : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

	float CastTime = 2.f;
	float RemainingCastTime = 0.f;

	//float represents the new cast time
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:

	//Defines an attribute I want to capture for calculation
	FGameplayEffectAttributeCaptureDefinition CastSpeedDef;
	
};
