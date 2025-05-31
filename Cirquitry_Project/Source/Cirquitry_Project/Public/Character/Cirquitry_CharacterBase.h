// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Pawn.h"
#include "Cirquitry_CharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;

UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_CharacterBase : public APawn
{
	GENERATED_BODY()

public:
	ACirquitry_CharacterBase();
	virtual  UAbilitySystemComponent* GetAbilitySystemComponent() const {return AbilitySystemComponent;}
	UAttributeSet* GetAttributeSet() const {return AttributeSet; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	virtual  void InitAbilityActorInfo();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPreCombatAttributes;

	void InitializePreCombatAttributes() const;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultCombatAttributes;

	void InitializeCombatAttributes() const;

};
