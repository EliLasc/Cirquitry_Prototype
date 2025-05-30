// Copyright Cirquitry


#include "UI/WidgetController/Cirquitry_OverWidgetController.h"

#include "AbilitySystem/Cirquitry_AbilitySystemComponent.h"
#include "AbilitySystem/Cirquitry_AttributeSet.h"

void UCirquitry_OverWidgetController::BroadcastInitialValues()
{
	//Player AttributeSet
	const UCirquitry_AttributeSet* PAttributeSet = CastChecked<UCirquitry_AttributeSet>(PlayerAttributeSet);

	OnHealthChanged.Broadcast(PAttributeSet->GetHealth());
	
	//Enemy AttributeSet
	const UCirquitry_AttributeSet* EAttributeSet = CastChecked<UCirquitry_AttributeSet>(EnemyAttributeSet);
	
	OnHealthChanged.Broadcast(EAttributeSet->GetHealth());
}

void UCirquitry_OverWidgetController::BindCallBacksToDependencies()
{
	//Player AttributeSet
	const UCirquitry_AttributeSet* PAttributeSet = CastChecked<UCirquitry_AttributeSet>(PlayerAttributeSet);

	//This binds the HealthChanged function to fire whenever the health attribute changes within the attribute set
	PlayerAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		PAttributeSet->GetHealthAttribute()).AddUObject(this, &UCirquitry_OverWidgetController::HealthChanged);

	//This is an anonymous function and can only access global things or stuff tied to "this" (overlaywidgetcontroller)
	//This allows for a bound event to fire when a new gameplay tag is added to the overlay widget controller
	Cast<UCirquitry_AbilitySystemComponent>(PlayerAbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			//gets the tag container of any effect applied to the players AbilitySystemComponent
			for (const FGameplayTag& Tag : AssetTags)
			{
				FGameplayTag DescriptionTag = FGameplayTag::RequestGameplayTag(FName("Description"));
				if (Tag.MatchesTag(DescriptionTag))
				{
					//if the gameplay effect has a description tag search the data table for any row names that match the tag and broadcast that row to listening widgets
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(DescriptionWidgetDataTable, Tag);
					DescriptionWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);

///
///
///
///
///
	
	//Enemy AttributeSet
	const UCirquitry_AttributeSet* EAttributeSet = CastChecked<UCirquitry_AttributeSet>(EnemyAttributeSet);

	//This binds the HealthChanged function to fire whenever the health attribute changes within the attribute set
//TODO: create a new enemy ability system component variable to use
	EnemyAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		EAttributeSet->GetHealthAttribute()).AddUObject(this, &UCirquitry_OverWidgetController::HealthChanged);

	//This is an anonymous function and can only access global things or stuff tied to "this" (overlaywidgetcontroller)
	//This allows for a bound event to fire when a new gameplay tag is added to the overlay widget controller
	Cast<UCirquitry_AbilitySystemComponent>(EnemyAbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			//gets the tag container of any effect applied to the players AbilitySystemComponent
			for (const FGameplayTag& Tag : AssetTags)
			{
				FGameplayTag DescriptionTag = FGameplayTag::RequestGameplayTag(FName("Description"));
				if (Tag.MatchesTag(DescriptionTag))
				{
					//if the gameplay effect has a description tag search the data table for any row names that match the tag and broadcast that row to listening widgets
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(DescriptionWidgetDataTable, Tag);
					DescriptionWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);
}

void UCirquitry_OverWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);

}
