// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Cirquitry_CombatInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCirquitry_CombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CIRQUITRY_PROJECT_API ICirquitry_CombatInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual int32 GetRound();
};
