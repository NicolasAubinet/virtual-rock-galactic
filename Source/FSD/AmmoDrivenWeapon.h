// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimatedItem.h"
#include "WeaponFireComponent.h"
#include "AmmoDrivenWeapon.generated.h"

/**
 * 
 */
UCLASS()
class FSD_API AAmmoDrivenWeapon : public AAnimatedItem
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable) void OnWeaponFireEnded() {};
	UFUNCTION(BlueprintCallable) void OnWeaponFired(FVector Location) {};
	UFUNCTION(BlueprintCallable) void InstantlyReload() {};
	UFUNCTION(BlueprintCallable) void All_StartReload() {};
	UFUNCTION(BlueprintCallable) void Server_StopReload() {};
	UFUNCTION(BlueprintCallable) void Server_ReloadWeapon() {};

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWeaponFireComponent* WeaponFire;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UAnimMontage* FP_FireAnimation;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite) int AmmoCount;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite) int ClipCount;
};
