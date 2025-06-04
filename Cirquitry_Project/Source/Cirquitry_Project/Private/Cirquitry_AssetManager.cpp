// Copyright Cirquitry


#include "Cirquitry_AssetManager.h"
#include "Cirquitry_GameplayTags.h"

UCirquitry_AssetManager& UCirquitry_AssetManager::Get()
{
	check(GEngine);
	
	UCirquitry_AssetManager* CirquitryAssetManager = Cast<UCirquitry_AssetManager>(GEngine->AssetManager);
	return *CirquitryAssetManager;
}

void UCirquitry_AssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FCirquitryGameplayTags::InitializeNativeGameplayTags();
}
