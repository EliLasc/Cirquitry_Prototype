// Copyright Cirquitry


#include "Player/Cirquitry_PlayerController.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/Cirquitry_AbilitySystemComponent.h"
#include "Input/Cirquitry_InputComponent.h"

ACirquitry_PlayerController::ACirquitry_PlayerController()
{
	bReplicates = true;
}

void ACirquitry_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(CirquitryContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem)
	{Subsystem->AddMappingContext(CirquitryContext, 0);}
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ACirquitry_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UCirquitry_InputComponent* CirquitryInputComponent = CastChecked<UCirquitry_InputComponent>(InputComponent);

	CirquitryInputComponent->BindAction(PauseMenu, ETriggerEvent::Triggered, this, &ACirquitry_PlayerController::Pause);

	CirquitryInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed,
		&ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}

UCirquitry_AbilitySystemComponent* ACirquitry_PlayerController::GetASC()
{
	if (Cirquitry_AbilitySystemComponent == nullptr)
	{
		Cirquitry_AbilitySystemComponent = Cast<UCirquitry_AbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	return Cirquitry_AbilitySystemComponent;
}


void ACirquitry_PlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	
}

void ACirquitry_PlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (GetASC() == nullptr) return;
	GetASC()->AbilityInputTagHeld(InputTag);
}

void ACirquitry_PlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	if (GetASC() == nullptr) return;
	GetASC()->AbilityInputTagHeld(InputTag);
}


