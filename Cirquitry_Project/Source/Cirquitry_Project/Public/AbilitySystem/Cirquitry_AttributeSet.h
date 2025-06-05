// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Cirquitry_AttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;
	
	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;
	
	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};

template<class T>
using TStaticFuncPtr = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API UCirquitry_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	public:
	UCirquitry_AttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;
	
	/*
	 *Combat Variables
	 */

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Combat Variables")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UCirquitry_AttributeSet, MaxHealth);

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData OldMaxHealth) const;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Combat Variables")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UCirquitry_AttributeSet, Health);

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData OldHealth) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BaseCircleMana, Category = "Combat Variables")
	FGameplayAttributeData BaseCircleMana;
	ATTRIBUTE_ACCESSORS(UCirquitry_AttributeSet, BaseCircleMana);

	UFUNCTION()
	void OnRep_BaseCircleMana(const FGameplayAttributeData OldBaseCircleMana) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BaseManaShield, Category = "Combat Variables")
	FGameplayAttributeData BaseManaShield;
	ATTRIBUTE_ACCESSORS(UCirquitry_AttributeSet, BaseManaShield);

	UFUNCTION()
	void OnRep_BaseManaShield(const FGameplayAttributeData OldBaseManaShield) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaShield, Category = "Combat Variables")
	FGameplayAttributeData ManaShield;
	ATTRIBUTE_ACCESSORS(UCirquitry_AttributeSet, ManaShield);

	UFUNCTION()
	void OnRep_ManaShield(const FGameplayAttributeData OldManaShield) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_DamageResistance, Category = "Combat Variables")
	FGameplayAttributeData DamageResistance;
	ATTRIBUTE_ACCESSORS(UCirquitry_AttributeSet, DamageResistance);

	UFUNCTION()
	void OnRep_DamageResistance(const FGameplayAttributeData OldDamageResistance) const;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CastSpeed, Category = "Combat Variables")
	FGameplayAttributeData CastSpeed;
	ATTRIBUTE_ACCESSORS(UCirquitry_AttributeSet, CastSpeed);

	UFUNCTION()
	void OnRep_CastSpeed(const FGameplayAttributeData OldCastSpeed) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CritChance, Category = "Combat Variables")
	FGameplayAttributeData CritChance;
	ATTRIBUTE_ACCESSORS(UCirquitry_AttributeSet, CritChance);

	UFUNCTION()
	void OnRep_CritChance(const FGameplayAttributeData OldCritChance) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Accuracy, Category = "Combat Variables")
	FGameplayAttributeData Accuracy;
	ATTRIBUTE_ACCESSORS(UCirquitry_AttributeSet, Accuracy);

	UFUNCTION()
	void OnRep_Accuracy(const FGameplayAttributeData OldAccuracy) const;
	
	/*
	 *PreCombat Variables
	 */

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_SpellCircleCount, Category = "PreCombat Variables")
	FGameplayAttributeData SpellCircleCount;
	ATTRIBUTE_ACCESSORS(UCirquitry_AttributeSet, SpellCircleCount);

	UFUNCTION()
	void OnRep_SpellCircleCount(const FGameplayAttributeData OldSpellCircleCount) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Wealth, Category = "PreCombat Variables")
	FGameplayAttributeData Wealth;
	ATTRIBUTE_ACCESSORS(UCirquitry_AttributeSet, Wealth);

	UFUNCTION()
	void OnRep_Wealth(const FGameplayAttributeData OldWealth) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Luck, Category = "PreCombat Variables")
	FGameplayAttributeData Luck;
	ATTRIBUTE_ACCESSORS(UCirquitry_AttributeSet, Luck);

	UFUNCTION()
	void OnRep_Luck(const FGameplayAttributeData OldLuck) const;



private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};
