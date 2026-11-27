#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "DamageData.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "Scrab.generated.h"

class UAudioComponent;
class UEnemyComponent;
class UFrozenPawnImpactComponent;
class UHealthComponentBase;
class UHitReactionComponent;
class UIKComponent;
class UOutlineComponent;
class UPathfinderReactiveTerrainTrackerComponent;
class UPawnAlertComponent;
class UPawnSensingComponent;
class UPawnStatsComponent;
class UWalkAndFlyEnemyComponent;

UCLASS(Blueprintable)
class FSD_API AScrab : public AEnemyDeepPathfinderCharacter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* WingAudio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyComponent* EnemyComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOutlineComponent* outline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWalkAndFlyEnemyComponent* WalkAndFly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPathfinderReactiveTerrainTrackerComponent* PathfinderReactiveTerrainTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPawnStatsComponent* PawnStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPawnSensingComponent* PawnSensing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPawnAlertComponent* Alert;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFrozenPawnImpactComponent* FrozenImpact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHitReactionComponent* HitReactions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UIKComponent* IK;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetTrackingRotationSpeed;
    
public:
    AScrab(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveStopFly();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveBeginFly();
    
    UFUNCTION(BlueprintCallable)
    void OnPathfinderStateChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnFreezeImpact();
    
    UFUNCTION(BlueprintCallable)
    void OnDamageTaken(float amount);
    
    UFUNCTION(BlueprintCallable)
    void OnBugDeath(UHealthComponentBase* Health);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_Ragdoll(const FVector_NetQuantize& Location, const FVector_NetQuantize& Impulse, uint8 BoneIndex);
    
public:
    UFUNCTION(BlueprintCallable)
    void AddImpulseAndRagdoll(const FDamageData& DamageData);
    
};

