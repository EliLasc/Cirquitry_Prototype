// Copyright Cirquitry


#include "Input/Cirquitry_InputConfig.h"

const UInputAction* UCirquitry_InputConfig::FindAbilityInputActionForTag(
	const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const FCirquitry_InputAction& Action: AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find AbilityInputAction for InputTag [%s], on InputConfig [%s]"), *InputTag.ToString(), *GetNameSafe(this));
	}

	return nullptr;
}
