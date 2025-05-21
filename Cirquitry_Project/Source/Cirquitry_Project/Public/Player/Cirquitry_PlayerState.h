// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "Character/Cirquitry_EnemyCharacter.h"
#include "Cirquitry_PlayerState.generated.h"


class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	ACirquitry_PlayerState();
	virtual  UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const {return AttributeSet; }
	ACirquitry_EnemyCharacter* GetEnemyCharacter() const {return EnemyCharacter; }
	
	UFUNCTION(BlueprintCallable) virtual void SpawnEnemy();
	
protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY()
	TObjectPtr<ACirquitry_EnemyCharacter> EnemyCharacter;

private:
	UPROPERTY(EditDefaultsOnly, Category = "EnemyCharacter")
	TSubclassOf<ACirquitry_EnemyCharacter> EnemyCharacterClass;
};
