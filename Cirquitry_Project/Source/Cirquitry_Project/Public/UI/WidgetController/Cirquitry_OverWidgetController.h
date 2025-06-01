// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/Cirquitry_WidgetController.h"
#include "Cirquitry_OverWidgetController.generated.h"

//Creates a struct to act as a base for a structure blueprint to be made from
USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag NameTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag RarityTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag TypeTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText NameText= FText();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DescriptionText= FText();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText TypeText = FText();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText RarityText = FText();
	
	//class is used to forward declare this since it isn't declared in this part of the script
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class UCirquitry_UserWidget> DescriptionWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* IconImage = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* TypeImage = nullptr;
};

class UCirquitry_UserWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDescriptionWidgetRowSignature, FUIWidgetRow, Row);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CIRQUITRY_PROJECT_API UCirquitry_OverWidgetController : public UCirquitry_WidgetController
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallBacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Description")
	FDescriptionWidgetRowSignature DescriptionWidgetRowDelegate;

protected:

	//Contains the data table of all descriptions that need to be displayed
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget Data")
	TObjectPtr<UDataTable> DescriptionWidgetDataTable;

	template<typename T>
	T* GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag);

};

template <typename T>
T* UCirquitry_OverWidgetController::GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag)
{
	return DataTable->FindRow<T>(Tag.GetTagName(), TEXT(""));;
}
