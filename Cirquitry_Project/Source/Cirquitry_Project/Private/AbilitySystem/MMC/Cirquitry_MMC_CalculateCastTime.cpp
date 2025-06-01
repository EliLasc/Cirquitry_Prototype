// Copyright Cirquitry


#include "AbilitySystem/MMC/Cirquitry_MMC_CalculateCastTime.h"
#include "AbilitySystem/Cirquitry_AttributeSet.h"
#include "Interaction/Cirquitry_CombatInterface.h"


float UCirquitry_MMC_CalculateCastTime::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	// Gather tags from source and target
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float ModifiedCastTime = 0.f;
	float CastSpeed = 0.f;

	//This sets the cast speed variable I'm using to equal the cast speed in the attributeset
	GetCapturedAttributeMagnitude(CastSpeedDef, Spec, EvaluationParameters, CastSpeed);
	ICirquitry_CombatInterface* CombatInterface = Cast<ICirquitry_CombatInterface>(Spec.GetContext().GetSourceObject());
	ModifiedCastTime = CastTime * CastSpeed;
	
	return CastSpeed;
}
