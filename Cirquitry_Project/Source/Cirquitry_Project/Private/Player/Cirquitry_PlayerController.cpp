// Copyright Cirquitry


#include "Player/Cirquitry_PlayerController.h"
#include "EnhancedInputSubsystems.h"
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

	//CirquitryInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed,
	//	&ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}

/*
 *
 *
void ACirquitry_PlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{GEngine->AddOnScreenDebugMessage(1, 3.f, FColor::Red, *InputTag.ToString());}

void ACirquitry_PlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{GEngine->AddOnScreenDebugMessage(2, 3.f, FColor::Blue, *InputTag.ToString());}

void ACirquitry_PlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{GEngine->AddOnScreenDebugMessage(3, 3.f, FColor::Green, *InputTag.ToString());}
 *
 *
 */


