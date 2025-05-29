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
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		PAttributeSet->GetHealthAttribute()).AddUObject(this, &UCirquitry_OverWidgetController::HealthChanged);
	
	//Enemy AttributeSet
	const UCirquitry_AttributeSet* EAttributeSet = CastChecked<UCirquitry_AttributeSet>(EnemyAttributeSet);

	//This binds the HealthChanged function to fire whenever the health attribute changes within the attribute set
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		EAttributeSet->GetHealthAttribute()).AddUObject(this, &UCirquitry_OverWidgetController::HealthChanged);

	//This returns the tags on the applying GameplayEffect
	Cast<UCirquitry_AbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg);
			}
		}
	);
}

void UCirquitry_OverWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);

}
