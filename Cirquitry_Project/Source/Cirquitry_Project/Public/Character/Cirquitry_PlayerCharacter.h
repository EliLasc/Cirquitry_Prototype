// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "Character/Cirquitry_CharacterBase.h"
#include "Cirquitry_PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_PlayerCharacter : public ACirquitry_CharacterBase
{
	GENERATED_BODY()

public:
	ACirquitry_PlayerCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
};
