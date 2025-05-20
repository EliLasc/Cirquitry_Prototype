// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Pawn.h"
#include "Cirquitry_CharacterBase.generated.h"

UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_CharacterBase : public APawn
{
	GENERATED_BODY()

public:
	ACirquitry_CharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
