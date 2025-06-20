// Copyright Cirquitry


#include "AbilitySystem/AbilityTasks/CalculateCastTime.h"
#include "AbilitySystem/Cirquitry_AttributeSet.h"
#include "Character/Cirquitry_CharacterBase.h"

UCalculateCastTime* UCalculateCastTime::UpdateCastTime(UGameplayAbility* OwningAbility)
{
	UCalculateCastTime* MyObj = NewAbilityTask<UCalculateCastTime>(OwningAbility);

	
	return MyObj;
}

void UCalculateCastTime::Activate()
{
	//float CastSpeed = UCirquitry_AttributeSet::GetCastSpeedAttribute();
	//ValidData.Broadcast(CastSpeed);
}
