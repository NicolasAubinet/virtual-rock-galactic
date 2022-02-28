#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "DecalData.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "CryosprayItem.generated.h"

class UDamageComponent;
class UParticleSystemComponent;
class UMotionAudioController;
class UProjectileLauncherComponent;
class UStickyFlameSpawner;
class UParticleSystem;
class UFSDAudioComponent;
class UItemUpgrade;
class UHealthComponentBase;
class UPrimitiveComponent;
class UFSDPhysicalMaterial;
class AProjectileBase;

UCLASS(Abstract)
class ACryosprayItem : public AAmmoDrivenWeapon {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Export, VisibleAnywhere)
    UProjectileLauncherComponent* ProjectileLauncher;
    
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere)
    UDamageComponent* DamageComponent;
    
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere)
    UStickyFlameSpawner* StickyFlames;
    
    UPROPERTY(Export, VisibleAnywhere)
    UDamageComponent* AoEColdDamageComponent;
    
    UPROPERTY(Export, VisibleAnywhere)
    UMotionAudioController* VelocityAudio;
    
    UPROPERTY(BlueprintReadWrite, Export, Transient)
    UParticleSystemComponent* FlameParticleComponent;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool PressurizedProjectileEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float PressurizedProjectileDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 PressurizeProjectileFullCost;
    
    UPROPERTY(EditAnywhere)
    UParticleSystem* ChargeupParticles;
    
    UPROPERTY(Export, Transient)
    UParticleSystemComponent* ChargeupParticleInstance;
    
    UPROPERTY(EditAnywhere)
    FDecalData ImpactDecal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DecalDelay;
    
    UPROPERTY(EditAnywhere)
    UParticleSystem* ImpactParticles;
    
    UPROPERTY(Export, Transient)
    UParticleSystemComponent* ImpactParticleInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FName> FlameParameterNames;
    
    UPROPERTY(EditAnywhere)
    float DamageSphereRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxFlameDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float FlameGrowthPerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float friendlyFireModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ChargeupTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ChargeDownTime;
    
    UPROPERTY(Transient, ReplicatedUsing=OnRep_IsCharging)
    bool isCharging;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ChargeProgress;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bRepressurerising;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RepressurerisingDoneAtPct;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ChargeUpFadeOutTime;
    
    UPROPERTY(BlueprintReadOnly, Export, VisibleAnywhere)
    UFSDAudioComponent* ChargeUpAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float PressureTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float PressureDropMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float PressureGainMultiplier;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CurrentPressure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RePressureDuration;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float RePressureProgress;
    
    UPROPERTY(Transient)
    TArray<UItemUpgrade*> upgrades;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool LongReachEnabled;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool AoEColdEnabled;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDoDamage(FVector_NetQuantize Start, FVector_NetQuantize End, uint8 Power);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_TriggerAoECold();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_PreLaunchProjectile();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveRepressurisingChanged(bool Value);
    
    UFUNCTION(BlueprintCallable)
    void OnTargetDamaged(UHealthComponentBase* Health, float Amount, UPrimitiveComponent* HitComponent, UFSDPhysicalMaterial* PhysicalMaterial);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsCharging(bool OldValue);
    
    UFUNCTION(BlueprintCallable)
    void OnProjectileSpawned(AProjectileBase* Projectile);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnProjectileLaunched(const FVector& Location);
    
    UFUNCTION(BlueprintCallable)
    void OnPressurizedPartileShoot();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPreProjectileLaunch();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PreLaunchProjectile();
    
public:
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    ACryosprayItem();
};

