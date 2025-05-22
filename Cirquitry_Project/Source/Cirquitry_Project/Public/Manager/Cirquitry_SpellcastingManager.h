// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "Cirquitry_SpellcastingManager.generated.h"

UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_SpellcastingManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ACirquitry_SpellcastingManager();

protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent>AbilitySystemComponent;

	UFUNCTION()
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;
};
