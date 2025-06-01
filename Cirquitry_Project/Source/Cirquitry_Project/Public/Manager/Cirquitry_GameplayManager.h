// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "UI/WidgetController/Cirquitry_OverWidgetController.h"
#include "Cirquitry_GameplayManager.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;

//Creates a struct to act as a base for a structure blueprint to be made from
USTRUCT(BlueprintType)
struct FSpellFunctionDataRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag ComponentTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag RarityTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag TypeTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag Element = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag DebuffEffect = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int DebuffStacks = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DebuffApplicationChance = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Accuracy = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CritChance = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CastTime = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int ManaCost = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int MinDamage = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int MaxDamage = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int DamageInstances = 0;
};

/** Notify interested parties that ability spec has been modified */
//DECLARE_MULTICAST_DELEGATE_OneParam(FAbilitySpecDirtied, const FGameplayAbilitySpec&);

/** Delegate for when an effect is applied */
//DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnGameplayEffectAppliedDelegate, UAbilitySystemComponent*, const FGameplayEffectSpec&, FActiveGameplayEffectHandle);

/** Returns a list of all attributes for this ability system component */
//UFUNCTION(BlueprintPure, Category="Gameplay Attributes")
//void GetAllAttributes(TArray<FGameplayAttribute>& OutAttributes);

/**
 * Returns the current value of the given gameplay attribute, or zero if the attribute is not found.
 * NOTE: This doesn't take predicted gameplay effect modifiers into consideration, so the value may not be accurate on clients at all times.
 *
 * @param Attribute The gameplay attribute to query
 * @param bFound Set to true if the attribute exists in this component
 */
//UFUNCTION(BlueprintPure, Category = "Gameplay Attributes")
//float GetGameplayAttributeValue(FGameplayAttribute Attribute, bool& bFound) const;

/** Remove all current AttributeSets and register the ones in the passed array. Note that it's better to call Add/Remove directly when possible. */
//void SetSpawnedAttributes(const TArray<UAttributeSet*>& NewAttributeSet);

/** A pending activation that cannot be activated yet, will be rechecked at a later point */

//struct FPendingAbilityInfo
//{
	//bool operator==(const FPendingAbilityInfo& Other) const
	//{
		// Don't compare event data, not valid to have multiple activations in flight with same key and handle but different event data
		//return PredictionKey == Other.PredictionKey	&& Handle == Other.Handle;
	//}

	/** Properties of the ability that needs to be activated */
	//FGameplayAbilitySpecHandle Handle;
	//FPredictionKey	PredictionKey;
	//FGameplayEventData TriggerEventData;

	/** True if this ability was activated remotely and needs to follow up, false if the ability hasn't been activated at all yet */
	//bool bPartiallyActivated;

	//FPendingAbilityInfo()
	//	: bPartiallyActivated(false)
	//{}
//};

/** Removes GameplayEffect by Handle. StacksToRemove=-1 will remove all stacks. */
//UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = GameplayEffects)
//virtual bool RemoveActiveGameplayEffect(FActiveGameplayEffectHandle Handle, int32 StacksToRemove=-1);

/** Return start time and total duration of a gameplay effect */
//void GetGameplayEffectStartTimeAndDuration(FActiveGameplayEffectHandle Handle, float& StartEffectTime, float& Duration) const;

/**
 * Raw accessor to ask the magnitude of a gameplay effect, not necessarily always correct. How should outside code (UI, etc) ask things like 'how much is this gameplay effect modifying my damage by'
 * (most likely we want to catch this on the backend - when damage is applied we can get a full dump/history of how the number got to where it is. But still we may need polling methods like below (how much would my damage be)
 */
//UFUNCTION(BlueprintCallable, Category = GameplayEffects)
//float GetGameplayEffectMagnitude(FActiveGameplayEffectHandle Handle, FGameplayAttribute Attribute) const;

/** Returns current stack count of an already applied GE */
//int32 GetCurrentStackCount(FActiveGameplayEffectHandle Handle) const;

/** Returns all active gameplay effects on this ASC */
//const FActiveGameplayEffectsContainer& GetActiveGameplayEffects() const;

/** Called when the duration of a gameplay effect has changed */
//virtual void OnGameplayEffectDurationChange(struct FActiveGameplayEffect& ActiveEffect);

/** A generic callback anytime an ability is activated (started) */
//FGenericAbilityDelegate AbilityActivatedCallbacks;

/** Callback anytime an ability is ended */
//FAbilityEnded AbilityEndedCallbacks;

/** Returns delegate structure that allows binding to several gameplay effect changes */
//FActiveGameplayEffectEvents* GetActiveEffectEventSet(FActiveGameplayEffectHandle Handle);
//FOnActiveGameplayEffectRemoved_Info* OnGameplayEffectRemoved_InfoDelegate(FActiveGameplayEffectHandle Handle);
//FOnActiveGameplayEffectStackChange* OnGameplayEffectStackChangeDelegate(FActiveGameplayEffectHandle Handle);
//FOnActiveGameplayEffectTimeChange* OnGameplayEffectTimeChangeDelegate(FActiveGameplayEffectHandle Handle);
//FOnActiveGameplayEffectInhibitionChanged* OnGameplayEffectInhibitionChangedDelegate(FActiveGameplayEffectHandle Handle);

UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_GameplayManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ACirquitry_GameplayManager();
	virtual void SetSpawnVariables(AActor* PC, AActor* EC);
	FSpellFunctionDataRow GetCurrentFunctionRow() {return CurrentSpellFunctionData;}

protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent>AbilitySystemComponent;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass, FSpellFunctionDataRow SpellFunctionDT);

	UFUNCTION(BlueprintCallable)
	void StartCasting(FGameplayTag EffectTag);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	bool bDestroyOnEffectRemoval = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	FSpellFunctionDataRow CurrentSpellFunctionData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	AActor* PlayerCharacter;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	AActor* EnemyCharacter;

	//Contains the data table of all descriptions that need to be displayed
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget Data")
	TObjectPtr<UDataTable> SpellFunctionDataTable;

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;

	template<typename T>
	T* GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag);
};

	template <typename T>
	T* ACirquitry_GameplayManager::GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag)
	{
		return DataTable->FindRow<T>(Tag.GetTagName(), TEXT(""));;
	}

