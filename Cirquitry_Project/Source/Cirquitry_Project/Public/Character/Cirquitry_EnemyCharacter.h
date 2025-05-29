// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Character/Cirquitry_CharacterBase.h"
#include "Cirquitry_EnemyCharacter.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_EnemyCharacter : public ACirquitry_CharacterBase
{
	GENERATED_BODY()
public:
	ACirquitry_EnemyCharacter();
	virtual  UAbilitySystemComponent* GetAbilitySystemComponent() const;
	UAttributeSet* GetAttributeSet() const {return AttributeSet; }
	
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
};
