// Copyright Cirquitry


#include "AbilitySystem/Cirquitry_AbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UI/WidgetController/Cirquitry_WidgetController.h"
#include "Player/Cirquitry_PlayerState.h"
#include "UI/HUD/Cirquitry_HUD.h"

UCirquitry_OverWidgetController* UCirquitry_AbilitySystemLibrary::GetOverlayWidgetController(
	const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (ACirquitry_HUD* CirquitryHUD = Cast<ACirquitry_HUD>(PC->GetHUD()))
		{
			ACirquitry_PlayerState* PS = PC->GetPlayerState<ACirquitry_PlayerState>();
			UAbilitySystemComponent* PASC = PS->GetAbilitySystemComponent();
			UAttributeSet* PAS = PS->GetAttributeSet();

			UAbilitySystemComponent* EASC = PS->GetEnemyAbilitySystemComponent();
			UAttributeSet* EAS = PS->GetEnemyAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, PASC, EASC, PAS, EAS);
			return CirquitryHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UCirquitry_AttrMenuController* UCirquitry_AbilitySystemLibrary::GetAttributeMenuWidgetController(
	const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (ACirquitry_HUD* CirquitryHUD = Cast<ACirquitry_HUD>(PC->GetHUD()))
		{
			ACirquitry_PlayerState* PS = PC->GetPlayerState<ACirquitry_PlayerState>();
			UAbilitySystemComponent* PASC = PS->GetAbilitySystemComponent();
			UAttributeSet* PAS = PS->GetAttributeSet();

			UAbilitySystemComponent* EASC = PS->GetEnemyAbilitySystemComponent();
			UAttributeSet* EAS = PS->GetEnemyAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, PASC, EASC, PAS, EAS);
			return CirquitryHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}
