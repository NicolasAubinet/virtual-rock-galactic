// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSDPlayerControllerBase.h"
#include "FSDPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FSD_API AFSDPlayerController : public AFSDPlayerControllerBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable) void ReadyToContinueFromEndScreen() {}
};
