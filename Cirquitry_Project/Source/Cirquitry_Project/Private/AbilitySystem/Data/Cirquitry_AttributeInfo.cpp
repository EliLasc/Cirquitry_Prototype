// Copyright Cirquitry


#include "AbilitySystem/Data/Cirquitry_AttributeInfo.h"

FCirquitryAttributeInfo UCirquitry_AttributeInfo::FindAttributeInfoForTag(
	const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FCirquitryAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find Info for AttributeTag [%s] on AttributeInfo [%s]."),
			*AttributeTag.ToString(), *GetNameSafe(this));
	}

	return FCirquitryAttributeInfo();
}
