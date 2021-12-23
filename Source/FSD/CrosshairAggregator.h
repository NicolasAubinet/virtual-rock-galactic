// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemAggregator.h"
#include "CrosshairAggregator.generated.h"

/**
 * 
 */
UCLASS()
class FSD_API UCrosshairAggregator : public UItemAggregator
{
	GENERATED_BODY()
	
		UFUNCTION(BlueprintCallable) UUserWidget* GetOrCreateCrosshair() { return nullptr; };
};
