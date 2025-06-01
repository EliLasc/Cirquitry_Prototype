// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "Character/Cirquitry_CharacterBase.h"
#include "Cirquitry_EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_EnemyCharacter : public ACirquitry_CharacterBase
{
	GENERATED_BODY()
public:
	ACirquitry_EnemyCharacter();

	virtual int32 GetRound() override;
	
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Round = 1;
};
