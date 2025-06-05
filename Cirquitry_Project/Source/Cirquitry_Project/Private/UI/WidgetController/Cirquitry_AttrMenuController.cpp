// Copyright Cirquitry


#include "UI/WidgetController/Cirquitry_AttrMenuController.h"
#include "AbilitySystem/Cirquitry_AttributeSet.h"
#include "AbilitySystem/Data/Cirquitry_AttributeInfo.h"
#include "Cirquitry_GameplayTags.h"

void UCirquitry_AttrMenuController::BindCallBacksToDependencies()
{
	
}

void UCirquitry_AttrMenuController::BroadcastInitialValues()
{
	UCirquitry_AttributeSet* PAS = CastChecked<UCirquitry_AttributeSet>(PlayerAttributeSet);
	UCirquitry_AttributeSet* EAS = CastChecked<UCirquitry_AttributeSet>(EnemyAttributeSet);

	check(PlayerAttributeInfo);

	for(auto& Pair : PAS->TagsToAttributes)
	{
		FCirquitryAttributeInfo PlayerInfo = PlayerAttributeInfo->FindAttributeInfoForTag(Pair.Key);
		PlayerInfo.AttributeValue = Pair.Value().GetNumericValue(PAS);
		AttributeInfoDelegate.Broadcast(PlayerInfo);
	}

	check(EnemyAttributeInfo);

	for(auto& Pair : EAS->TagsToAttributes)
	{
		FCirquitryAttributeInfo EnemyInfo = EnemyAttributeInfo->FindAttributeInfoForTag(Pair.Key);
		EnemyInfo.AttributeValue = Pair.Value().GetNumericValue(EAS);
		AttributeInfoDelegate.Broadcast(EnemyInfo);
	}
}
