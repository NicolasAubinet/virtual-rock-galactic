// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraComponent.h"
#include "FirstPersonNiagaraComponent.generated.h"

/**
 * 
 */
UCLASS()
class FSD_API UFirstPersonNiagaraComponent : public UNiagaraComponent
{
	GENERATED_BODY()
	
		UFUNCTION(BlueprintCallable) UNiagaraComponent* SpawnFirstPersonEmitterAttached(UNiagaraSystem* inNiagaraSystem, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale, EAttachLocation::Type LocationType, bool inAutoDestroy) { return nullptr; };
};
