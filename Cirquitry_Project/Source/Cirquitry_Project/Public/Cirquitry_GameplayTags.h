// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * AuraGameplayTags
 *
 * Singleton containing native Gameplay Tags
 */

struct FCirquitryGameplayTags
{
public:
	static const FCirquitryGameplayTags& Get() { return GameplayTags;}
	static void InitializeNativeGameplayTags();

//TODO: Check is these need to all be float variables
	
	/**
	 *PreCombat Attributes
	 */

	FGameplayTag Attributes_PreCombat_SpellCircleCount;
	FGameplayTag Attributes_PreCombat_Wealth;
	FGameplayTag Attributes_PreCombat_Luck;

	/**
	 *Combat Attributes
	 */

	FGameplayTag Attributes_Combat_MaxHealth;
	FGameplayTag Attributes_Combat_Health;
	FGameplayTag Attributes_Combat_BaseCircleMana;
	FGameplayTag Attributes_Combat_BaseManaShield;
	FGameplayTag Attributes_Combat_ManaShield;
	FGameplayTag Attributes_Combat_DamageResistance;
	FGameplayTag Attributes_Combat_CastSpeed;
	FGameplayTag Attributes_Combat_CritChance;
	FGameplayTag Attributes_Combat_Accuracy;

	/*
	 *Enhanced Inputs
	 */

	FGameplayTag InputTag_ESC;
	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;

protected:

private:
	static FCirquitryGameplayTags GameplayTags;
};
