// Copyright Cirquitry

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cirquitry_SpellEffectActor.generated.h"

UCLASS()
class CIRQUITRY_PROJECT_API ACirquitry_SpellEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACirquitry_SpellEffectActor();

	UFUNCTION()
	void OnSpellComponentCast(AActor* TargetActor);

protected:
	virtual void BeginPlay() override;
	
};
