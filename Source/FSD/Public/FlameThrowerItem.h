#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AmmoDrivenWeapon.h"
#include "DecalData.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "UObject/NoExportTypes.h"
#include "FlameThrowerItem.generated.h"

class UStatusEffect;
class UMotionAudioController;
class UParticleSystemComponent;
class UDamageComponent;
class USoundCue;
class UStickyFlameSpawner;
class UParticleSystem;
class UItemUpgrade;
class UProjectileLauncherBaseComponent;
class AActor;
class UFSDPhysicalMaterial;
class UHealthComponentBase;
class UPrimitiveComponent;

UCLASS(Abstract)
class AFlameThrowerItem : public AAmmoDrivenWeapon {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Export, Transient)
    UParticleSystemComponent* FlameParticleComponent;
    
    UPROPERTY(Export, VisibleAnywhere)
    UDamageComponent* DamageComponent;
    
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere)
    UStickyFlameSpawner* StickyFlames;
    
    UPROPERTY(Export, VisibleAnywhere)
    UDamageComponent* AoEHeatDamageComponent;
    
    UPROPERTY(Export, VisibleAnywhere)
    UDamageComponent* ExplodingTargetsDamageComponent;
    
    UPROPERTY(Export, VisibleAnywhere)
    UMotionAudioController* MotionAudio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 ShotCostProjectile;
    
    UPROPERTY(EditAnywhere)
    FDecalData ImpactDecal;
    
    UPROPERTY(EditAnywhere)
    float DecalDelay;
    
    UPROPERTY(Transient)
    float CurrentDecalDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UParticleSystem* ImpactParticles;
    
    UPROPERTY(BlueprintReadWrite, Export, Transient)
    UParticleSystemComponent* ImpactParticleInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UParticleSystem* FP_LongReachParticles;
    
    UPROPERTY(EditAnywhere)
    UParticleSystem* TP_LongReachParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float VeryLongReachThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UParticleSystem* FP_VeryLongReachParticles;
    
    UPROPERTY(EditAnywhere)
    UParticleSystem* TP_VeryLongReachParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FName> FlameParameterNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DamageSphereRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxFlameDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float FlameGrowthPerSecond;
    
    UPROPERTY(EditAnywhere)
    float FlameEndPointResponsiveness;
    
    UPROPERTY(EditAnywhere)
    float FlameIntensityPerSecond;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<UStatusEffect> OnFireStatusEffect;
    
    UPROPERTY(EditAnywhere)
    float ChanceToFleeOnDamage;
    
    UPROPERTY(EditAnywhere)
    float MeltPointRadius;
    
    UPROPERTY(EditAnywhere)
    float MeltPointBuildTime;
    
    UPROPERTY(EditAnywhere)
    float MeltCarveTime;
    
    UPROPERTY(EditAnywhere)
    UParticleSystem* MeltSteamParticle;
    
    UPROPERTY(Transient)
    TArray<UItemUpgrade*> upgrades;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool LongReachEnabled;
    
    UPROPERTY(Transient)
    bool AoEHeatEnabled;
    
    UPROPERTY(Transient)
    float KilledTargetsExplosionChance;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ShowDamageParticle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UParticleSystem* DamangeTargetsParticles;
    
    UPROPERTY(EditAnywhere)
    UParticleSystem* KilledTargetsExplodingParticles;
    
    UPROPERTY(EditAnywhere)
    USoundCue* KilledTargetsExplodingSound;
    
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere)
    UProjectileLauncherBaseComponent* ProjectileLancher;
    
    UFUNCTION(BlueprintCallable)
    void TriggerAoEHeat();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerMeltIce(const TArray<FVector>& meltPoints);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDoDamage(FVector_NetQuantize Start, FVector_NetQuantize End);
    
    UFUNCTION(BlueprintCallable)
    void OnTargetKilled(AActor* Target, UFSDPhysicalMaterial* PhysMat);
    
    UFUNCTION(BlueprintCallable)
    void OnTargetDamaged(UHealthComponentBase* Health, float Amount, UPrimitiveComponent* HitComponent, UFSDPhysicalMaterial* PhysicalMaterial);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowTargetBurstIntoFire(FVector_NetQuantize Location, FRotator Rotation);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_FlameFeedback(FVector_NetQuantize Location, FRotator Rotation);
    
public:
    AFlameThrowerItem();
};

