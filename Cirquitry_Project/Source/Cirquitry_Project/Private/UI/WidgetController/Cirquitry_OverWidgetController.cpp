// Copyright Cirquitry


#include "UI/WidgetController/Cirquitry_OverWidgetController.h"

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
}

void UCirquitry_OverWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);

}
