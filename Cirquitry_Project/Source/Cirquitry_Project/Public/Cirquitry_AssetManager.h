// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "Cirquitry_AssetManager.generated.h"

/**
 * 
 */
UCLASS()
class CIRQUITRY_PROJECT_API UCirquitry_AssetManager : public UAssetManager
{
	GENERATED_BODY()

public:

	//This returns a reference to the AssetManager
	static UCirquitry_AssetManager& Get();

protected:

	virtual void StartInitialLoading() override;
};
