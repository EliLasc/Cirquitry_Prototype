// Copyright Cirquitry


#include "Manager/Cirquitry_GameplayManager.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/Cirquitry_AbilitySystemComponent.h"

// Sets default values
ACirquitry_GameplayManager::ACirquitry_GameplayManager()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UCirquitry_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

void ACirquitry_GameplayManager::SetSpawnVariables(AActor* PC, AActor* EC)
{
	PlayerCharacter = PC;
	EnemyCharacter = EC;
}

void ACirquitry_GameplayManager::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass, FSpellFunctionDataRow SpellFunctionDT)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) return;

	CurrentSpellFunctionData = SpellFunctionDT;
	
	check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);
	
	const FActiveGameplayEffectHandle ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}

void ACirquitry_GameplayManager::StartCasting(FGameplayTag EffectTag)
{
	CurrentSpellFunctionData = *GetDataTableRowByTag<FSpellFunctionDataRow>(SpellFunctionDataTable, EffectTag);
	float CastTime = CurrentSpellFunctionData.CastTime;
}

