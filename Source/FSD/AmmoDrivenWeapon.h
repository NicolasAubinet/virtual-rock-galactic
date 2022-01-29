#pragma once

#include "CoreMinimal.h"
#include "AnimatedItem.h"
#include "WeaponFireComponent.h"
#include "FSD_struct.h"
#include "AmmoDrivenWeapon.generated.h"

UCLASS()
class FSD_API AAmmoDrivenWeapon : public AAnimatedItem
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable) void OnWeaponFireEnded() {};
	UFUNCTION(BlueprintCallable) void OnWeaponFired(FVector Location) {};
	UFUNCTION(BlueprintCallable) void RecieveFiredWeapon() {};
	UFUNCTION(BlueprintCallable) void InstantlyReload() {};
	UFUNCTION(BlueprintCallable) void All_StartReload() {};
	UFUNCTION(BlueprintCallable) void Server_StopReload() {};
	UFUNCTION(BlueprintCallable) void Server_ReloadWeapon() {};
	UFUNCTION(BlueprintCallable) void Server_PlayBurstFire(int shotCount) {};

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWeaponFireComponent* WeaponFire;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UAnimMontage* FP_FireAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UAnimMontage* WPN_Fire;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UAnimMontage* WPN_Reload;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite) UFXSystemAsset* CasingParticles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool UseTriggeredCasingParticleSystem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) ULightComponent* MuzzleFlashLight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FRuntimeFloatCurve MuzzleFlashLightCurve;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 BulletsRemainingForNearEmptySound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 MaxAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ClipSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ShotCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 AmmoCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ClipCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 BurstCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float BurstCycleTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float RateOfFire;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool HasAutomaticFire;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float ReloadTimeLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float FireSoundFadeDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float FireSoundDelayToTail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EAmmoWeaponState WeaponState;
};
