// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSD_struct.h"
#include "WindowManager.h"
#include "GameFramework/PlayerController.h"
#include "FSDPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class FSD_API AFSDPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UMaterialParameterCollection* GlobalMaterialParameterCollection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWindowManager* WindowManager;

	UFUNCTION(BlueprintCallable) void SetHUDVisible(bool IsVisible, enum EHUDVisibilityReason reason) {};
	UFUNCTION(BlueprintCallable) void ToggleAnalogCursor(bool Visible) {};
};
