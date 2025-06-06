// Copyright Cirquitry


#include "Cirquitry_GameplayTags.h"
#include "GameplayTagsManager.h"

FCirquitryGameplayTags FCirquitryGameplayTags::GameplayTags;

void FCirquitryGameplayTags::InitializeNativeGameplayTags()
{

	/**
	 *PreCombat Attributes
	 */
	
	GameplayTags.Attributes_PreCombat_SpellCircleCount = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.PreCombat.SpellCircleCount"), FString("The number of spell circles available to the player"));

	GameplayTags.Attributes_PreCombat_Wealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.PreCombat.Wealth"), FString("The player's current wealth"));

	GameplayTags.Attributes_PreCombat_Luck = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.PreCombat.Luck"), FString("The player's luck with rarity generation"));
	
	/**
	 *Combat Attributes
	 */

	GameplayTags.Attributes_Combat_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Combat.MaxHealth"), FString("The player's max possible health"));

	GameplayTags.Attributes_Combat_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Combat.Health"), FString("The player's current health"));

	GameplayTags.Attributes_Combat_BaseCircleMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Combat.BaseCircleMana"), FString("The starting max mana for new magic circles"));

	GameplayTags.Attributes_Combat_BaseManaShield = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Combat.BaseManaShield"), FString("The player's starting combat mana shield"));

	GameplayTags.Attributes_Combat_ManaShield = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Combat.ManaShield"), FString("The player's current combat mana shield"));

	GameplayTags.Attributes_Combat_DamageResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Combat.DamageResistance"), FString("The player's resistance to non-debuff damage"));

	GameplayTags.Attributes_Combat_CastSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Combat.CastSpeed"), FString("The player's speed in which they cast spell components"));

	GameplayTags.Attributes_Combat_CritChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Combat.CritChance"), FString("The player's chance to crit any cast spell components"));

	GameplayTags.Attributes_Combat_Accuracy = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Combat.Accuracy"), FString("The player's chance to hit any cast spell components"));

	/*
	 *Enhanced Inputs
	 */
	
	GameplayTags.InputTag_ESC = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.ESC"), FString("Input Tag for ESC Key"));

	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.LMB"), FString("Input Tag for Left Mouse Button"));

	GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.RMB"), FString("Input Tag for Right Mouse Button"));

	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.1"), FString("Input Tag for 1 key"));

	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.2"), FString("Input Tag for 2 key"));

	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.3"), FString("Input Tag for 3 key"));

	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.4"), FString("Input Tag for 14key"));

}
