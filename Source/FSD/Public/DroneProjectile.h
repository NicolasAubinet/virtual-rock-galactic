#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Projectile.h"
#include "DroneProjectile.generated.h"

class AActor;
class ADroneLauncherItem;
class UAudioComponent;
class UDamageComponent;
class UHealthComponentBase;
class UPrimitiveComponent;
class UProjectileExplosion;
class USoundCue;
class USphereComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class FSD_API ADroneProjectile : public AProjectile {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* HomingTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* ReturnTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* DroneLoop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* Damage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProjectileExplosion* ProjectileExplosion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* DroneLaunchCue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_HitResult, meta=(AllowPrivateAccess=true))
    FHitResult HitResult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ADroneLauncherItem* DroneLauncher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxImpacts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 Impacts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFlightDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float FlightDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxReturnDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ReturnDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Returning, meta=(AllowPrivateAccess=true))
    bool bReturning;
    
public:
    ADroneProjectile(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetupHoming(const FHitResult& NewHitResult);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnTargetDied(UHealthComponentBase* HealthComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Returning();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_HitResult();
    
    UFUNCTION(BlueprintCallable)
    void OnLauncherEquipStateChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnHomingTargetBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCompleteReturn();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginReturn();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UHealthComponentBase* GetTargetHealthComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTarget();
    
    UFUNCTION(BlueprintCallable)
    void DoReturnCheck(AActor* hitTarget);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_NotifyReturnComplete();
    
};

