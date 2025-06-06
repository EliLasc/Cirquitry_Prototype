// Copyright Cirquitry


#include "AbilitySystem/Cirquitry_AbilitySystemComponent.h"

#include "Cirquitry_GameplayTags.h"
#include "AbilitySystem/Abilities/Cirquitry_GameplayAbility.h"

void UCirquitry_AbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UCirquitry_AbilitySystemComponent::EffectApplied);
}

void UCirquitry_AbilitySystemComponent::AddCharacterAbilities(
	const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	//This will read the spell components the player has equipped and give them to the character as abilities
	for (const TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		if(const UCirquitry_GameplayAbility* CirquitryAbility = Cast<UCirquitry_GameplayAbility>(AbilitySpec.Ability))
		{
			//This would be changed out later since abilities won't activate using player inputs
			AbilitySpec.DynamicAbilityTags.AddTag(CirquitryAbility->StartupInputTag);
			
			GiveAbility(AbilitySpec);
		}
	}
}

void UCirquitry_AbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                                      const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
	
	for (const FGameplayTag& Tag : TagContainer)
	{
		//TODO: Broadcast the tag to the Widget Controller
		const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg);
	}
}
