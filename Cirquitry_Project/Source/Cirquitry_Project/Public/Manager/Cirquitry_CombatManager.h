// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "Cirquitry_CombatManager.generated.h"

UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_CombatManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ACirquitry_CombatManager();

protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent>AbilitySystemComponent;
};
