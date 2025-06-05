// Copyright Cirquitry


#include "UI/WidgetController/Cirquitry_AttrMenuController.h"
#include "AbilitySystem/Cirquitry_AttributeSet.h"
#include "AbilitySystem/Data/Cirquitry_AttributeInfo.h"
#include "Cirquitry_GameplayTags.h"

void UCirquitry_AttrMenuController::BindCallBacksToDependencies()
{
	UCirquitry_AttributeSet* PAS = CastChecked<UCirquitry_AttributeSet>(PlayerAttributeSet);
	check(PlayerAttributeInfo);
	for(auto& Pair : PAS->TagsToAttributes)
	{
		PlayerAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
	[this, Pair](const FOnAttributeChangeData& Data)
		{BroadcastPlayerAttributeInfo(Pair.Key, Pair.Value());});
	}

	UCirquitry_AttributeSet* EAS = CastChecked<UCirquitry_AttributeSet>(EnemyAttributeSet);
	check(EnemyAttributeInfo);
	for(auto& Pair : EAS->TagsToAttributes)
	{
		PlayerAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
	[this, Pair](const FOnAttributeChangeData& Data)
		{BroadcastEnemyAttributeInfo(Pair.Key, Pair.Value());});
	}
}

void UCirquitry_AttrMenuController::BroadcastInitialValues()
{
	UCirquitry_AttributeSet* PAS = CastChecked<UCirquitry_AttributeSet>(PlayerAttributeSet);
	UCirquitry_AttributeSet* EAS = CastChecked<UCirquitry_AttributeSet>(EnemyAttributeSet);

	check(PlayerAttributeInfo);
	for(auto& Pair : PAS->TagsToAttributes)
	{BroadcastPlayerAttributeInfo(Pair.Key, Pair.Value());}

	check(EnemyAttributeInfo);
	for(auto& Pair : EAS->TagsToAttributes)
	{BroadcastEnemyAttributeInfo(Pair.Key, Pair.Value());}
}

void UCirquitry_AttrMenuController::BroadcastPlayerAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const
{
	FCirquitryAttributeInfo PlayerInfo = PlayerAttributeInfo->FindAttributeInfoForTag(AttributeTag);
	PlayerInfo.AttributeValue = Attribute.GetNumericValue(PlayerAttributeSet);
	AttributeInfoDelegate.Broadcast(PlayerInfo);
}

void UCirquitry_AttrMenuController::BroadcastEnemyAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const
{
	FCirquitryAttributeInfo EnemyInfo = EnemyAttributeInfo->FindAttributeInfoForTag(AttributeTag);
	EnemyInfo.AttributeValue = Attribute.GetNumericValue(EnemyAttributeSet);
	AttributeInfoDelegate.Broadcast(EnemyInfo);
}
