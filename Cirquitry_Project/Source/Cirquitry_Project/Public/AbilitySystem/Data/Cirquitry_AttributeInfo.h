// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Cirquitry_AttributeInfo.generated.h"

USTRUCT(BlueprintType)
struct FCirquitryAttributeInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag AttributeTag = FGameplayTag();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeName = FText();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeDescription = FText();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool IsPercentage = false;

	//This determines the type of variable that the attributes on the attribute set will be (float)
	UPROPERTY(BlueprintReadOnly)
	float AttributeValue = 0.f;
};

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API UCirquitry_AttributeInfo : public UDataAsset
{
	GENERATED_BODY()
public:

	FCirquitryAttributeInfo FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound = false) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FCirquitryAttributeInfo> AttributeInformation;
};
