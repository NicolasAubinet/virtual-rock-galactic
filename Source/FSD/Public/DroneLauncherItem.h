#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "DroneLauncherItem.generated.h"

class ADroneProjectile;
class AProjectile;
class AProjectileBase;
class UProjectileLauncherComponent;

UCLASS(Abstract, Blueprintable)
class FSD_API ADroneLauncherItem : public AAmmoDrivenWeapon {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProjectileLauncherComponent* projectileLauncher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EquippedReturnSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UnequippedReturnSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ADroneProjectile*> ActiveDrones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 ActiveDroneCount;
    
public:
    ADroneLauncherItem(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RequestAllDronesReturn();
    
    UFUNCTION(BlueprintCallable)
    void OnDroneSpawned(AProjectileBase* Projectile);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnDroneReturned(AProjectile* DroneProjectile);
    
};

