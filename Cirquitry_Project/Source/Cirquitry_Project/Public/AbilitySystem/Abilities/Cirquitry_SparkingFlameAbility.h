// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/Cirquitry_GameplayAbility.h"
#include "Cirquitry_SparkingFlameAbility.generated.h"

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API UCirquitry_SparkingFlameAbility : public UCirquitry_GameplayAbility
{
	GENERATED_BODY()

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
