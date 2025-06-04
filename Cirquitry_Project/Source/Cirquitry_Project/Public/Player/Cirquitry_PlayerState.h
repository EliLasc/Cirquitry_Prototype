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
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual  UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const {return AttributeSet; }
	virtual  UAbilitySystemComponent* GetEnemyAbilitySystemComponent() const;
	UAttributeSet* GetEnemyAttributeSet() const {return AttributeSet; }

	void SetEnemyGAS(UAbilitySystemComponent* EASC, UAttributeSet* EAS);

	FORCEINLINE int32 GetRound() const { return Round; }
	
protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> EnemyAbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> EnemyAttributeSet;

private:

	UPROPERTY(VisibleAnywhere, ReplicatedUsing=OnRep_Round)
	int32 Round = 1;

	UFUNCTION()
	void OnRep_Round(int32 OldRound);
};
