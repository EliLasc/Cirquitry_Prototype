// Copyright Cirquitry


#include "AbilitySystem/Abilities/Cirquitry_SparkingFlameAbility.h"

#include "Kismet/KismetSystemLibrary.h"

void UCirquitry_SparkingFlameAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	UKismetSystemLibrary::PrintString(this, FString("ActivateAblity (C++)"),
		true, true, FLinearColor::Yellow, 3);
}
