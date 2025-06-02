// Copyright Cirquitry


#include "AbilitySystem/MMC/Cirquitry_MMC_SparkingFlame.h"
#include "AbilitySystem/Cirquitry_AttributeSet.h"
#include "Manager/Cirquitry_GameplayManager.h"

UCirquitry_MMC_SparkingFlame::UCirquitry_MMC_SparkingFlame()
{
	HealthDef.AttributeToCapture = UCirquitry_AttributeSet::GetHealthAttribute();
	HealthDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	HealthDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(HealthDef);
}

float UCirquitry_MMC_SparkingFlame::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	//This gets the GameplayManager that cast the gameplay effect
	FSpellFunctionDataRow CurrentSpellFunctionData = Cast<ACirquitry_GameplayManager>(Spec.GetContext().GetSourceObject())->GetCurrentFunctionRow();

	int minDamage = CurrentSpellFunctionData.MinDamage;
	int maxDamage = CurrentSpellFunctionData.MaxDamage;
	
	float Health = 0.f;
	GetCapturedAttributeMagnitude(HealthDef, Spec, EvaluationParameters, Health);
	int damage = (rand() % (maxDamage - minDamage + 1)) + minDamage;

	return FMath::Max<float>(Health - damage, 0.f);	
}
