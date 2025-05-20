// Copyright Cirquitry


#include "UI/WidgetController/Cirquitry_OverWidgetController.h"

#include "AbilitySystem/Cirquitry_AttributeSet.h"

void UCirquitry_OverWidgetController::BroadcastInitialValues()
{
	//Player AttributeSet
	const UCirquitry_AttributeSet* PlayerAttributeSet = CastChecked<UCirquitry_AttributeSet>(AttributeSet);

	//Enemy AttributeSet
	//const UCirquitry_AttributeSet* EnemyAttributeSet = CastChecked<UCirquitry_AttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(PlayerAttributeSet->GetHealth());
	//OnMaxHealthChanged.Broadcast(PlayerAttributeSet->GetMaxHealth())
}

void UCirquitry_OverWidgetController::BindCallBacksToDependencies()
{
	//Player AttributeSet
	const UCirquitry_AttributeSet* PlayerAttributeSet = CastChecked<UCirquitry_AttributeSet>(AttributeSet);

	//Enemy AttributeSet
	//const UCirquitry_AttributeSet* EnemyAttributeSet = CastChecked<UCirquitry_AttributeSet>(AttributeSet);


	//This binds the HealthChanged function to fire whenever the health attribute changes withing the attribute set
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		PlayerAttributeSet->GetHealthAttribute()).AddUObject(this, &UCirquitry_OverWidgetController::HealthChanged);
}

void UCirquitry_OverWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);

}
