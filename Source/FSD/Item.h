// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class FSD_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	UFUNCTION(BlueprintCallable) void Server_StartUsing(bool IsUsing) {}
	UFUNCTION(BlueprintCallable) void RecieveStopUsing() {}
	UFUNCTION(BlueprintCallable) void RecieveStartUsing() {}

	//UPROPERTY(EditAnywhere, BlueprintReadWrite) UCurveFloat* HeatCurve; // 0x2c8(0x08)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float ManualHeatPerUse; // 0x2d0(0x04)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CooldownRate; // 0x2d4(0x04)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float ManualCooldownDelay; // 0x2d8(0x04)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float UnjamDuration; // 0x2dc(0x04)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CurrentTemperature; // 0x2e4(0x04)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USoundBase* AudioTemperature; // 0x2e8(0x08)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float AudioTemperatureFadeout; // 0x2f0(0x04)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName TemperatureFloatParam; // 0x2f4(0x08)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UAudioComponent* TemperatureAudioComponent; // 0x300(0x08)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool Overheated; // 0x308(0x01)
	//UPROPERTY(EditAnywhere, BlueprintReadWrite) UDialogDataAsset* ShoutOverheated; // 0x310(0x08)
};
