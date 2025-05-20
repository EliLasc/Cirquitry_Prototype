// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "Cirquitry_CirquitryManager.generated.h"

class UAbilitySystemComponent;
UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_CirquitryManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ACirquitry_CirquitryManager();

protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent>AbilitySystemComponent;


};
