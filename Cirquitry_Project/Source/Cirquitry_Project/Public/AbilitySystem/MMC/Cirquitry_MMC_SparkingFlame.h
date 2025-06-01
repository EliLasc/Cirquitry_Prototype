// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "Cirquitry_MMC_SparkingFlame.generated.h"

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API UCirquitry_MMC_SparkingFlame : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	UCirquitry_MMC_SparkingFlame();

	//float represents the new health value
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:

	//Defines an attribute I want to capture for calculation
	FGameplayEffectAttributeCaptureDefinition HealthDef;
};
