// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/Cirquitry_WidgetController.h"
#include "Game/Cirquitry_GameInstance.h"
#include "Cirquitry_OverWidgetController.generated.h"

class UCirquitry_UserWidget;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);

//Creates a struct to act as a base for a structure blueprint to be made from
USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag MessageTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Message = FText();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UCirquitry_UserWidget> MessageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Image = nullptr;
};

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
	FOnHealthChangedSignature OnHealthChanged;

protected:

	//Contains the data table of all descriptions that need to be displayed
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget Data")
	TObjectPtr<UDataTable> DescriptionWidgetDataTable;
	
	void HealthChanged(const FOnAttributeChangeData& Data) const;

	UPROPERTY()
	TObjectPtr<UCirquitry_GameInstance> GameInstance;

	template<typename T>
	T* GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag);

};

template <typename T>
T* UCirquitry_OverWidgetController::GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag)
{
	return DataTable->FindRow<T>(Tag.GetTagName(), TEXT(""));;
}
