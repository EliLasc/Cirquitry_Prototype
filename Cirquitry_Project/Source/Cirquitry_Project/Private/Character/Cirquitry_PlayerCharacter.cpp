// Copyright Cirquitry


#include "Character/Cirquitry_PlayerCharacter.h"

#include "Player/Cirquitry_PlayerState.h"

ACirquitry_PlayerCharacter::ACirquitry_PlayerCharacter()
{
	
}

void ACirquitry_PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void ACirquitry_PlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Init ability actor info for the client
	InitAbilityActorInfo();
}

void ACirquitry_PlayerCharacter::InitAbilityActorInfo()
{
	ACirquitry_PlayerState* Cirquitry_PlayerState = GetPlayerState<ACirquitry_PlayerState>();
	check(Cirquitry_PlayerState);
	Cirquitry_PlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(Cirquitry_PlayerState, this);
	AbilitySystemComponent = Cirquitry_PlayerState->GetAbilitySystemComponent();
	AttributeSet = Cirquitry_PlayerState->GetAttributeSet();
}
