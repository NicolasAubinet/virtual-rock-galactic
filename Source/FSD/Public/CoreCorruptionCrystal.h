#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Pawn.h"
#include "Curves/CurveFloat.h"
#include "Engine/NetSerialization.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "BossFightInterface.h"
#include "CoreCorruptionCrystalDelegateDelegate.h"
#include "DamageData.h"
#include "ECoreCorruptionCrystalState.h"
#include "PillarBeam.h"
#include "CoreCorruptionCrystal.generated.h"

class AActor;
class ACoreCorruptionPillar;
class ACoreCorruptionRift;
class UAudioComponent;
class UCapsuleComponent;
class UCoreCorruptionPillarSpawnerComponent;
class UCurveVector;
class UDamageComponent;
class UDamageTag;
class UEnemyComponent;
class UEnemyHealthComponent;
class UHealthComponent;
class UNiagaraComponent;
class UNiagaraSystem;
class UPathfinderCollisionComponent;
class UPhysicalMaterial;
class UPointLightComponent;
class UPrimitiveComponent;
class URotatingSceneComponent;
class USceneComponent;
class USkeletalMeshComponent;
class USoundCue;
class USphereComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class FSD_API ACoreCorruptionCrystal : public APawn, public IGameplayTagAssetInterface, public IBossFightInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URotatingSceneComponent* Bobber;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URotatingSceneComponent* Rotator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* CrystalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* WeakpointCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPathfinderCollisionComponent* ShieldCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ShieldMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* KnockbackSphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPointLightComponent* Light;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPointLightComponent* LargeLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* EnergyParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* InvulnerableParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyHealthComponent* Health;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCoreCorruptionPillarSpawnerComponent* PillarSpawner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyComponent* enemy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* KnockbackDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* EndExplosionDamage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCoreCorruptionCrystalDelegate OnStateChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ACoreCorruptionRift* Rift;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ACoreCorruptionPillar* Pillar;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BeamTargetParamName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPillarBeam> SpawnBeams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> KnockbackTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* DeathRattle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve KnockBackCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhysicalMaterial* InvulnerableOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhysicalMaterial* WeakPointMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* AliveSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USoundCue*> IdleRumbleCues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ShieldsUpCue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ShieldsDownCue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* BeamShootSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* BeamImpactSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* DeathCue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* PushBackSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* PushBackEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* SpawnBeamEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* SpawnBeamImpactEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ShieldBeamLifeTimeMaxParamName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ShieldBeamLifeTimeMinParamName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeathDisplayTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeathIntoRiftTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float KnockBackInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BossHealthBarDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    ECoreCorruptionCrystalState State;
    
public:
    ACoreCorruptionCrystal(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StopWave();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartWave();
    
    UFUNCTION(BlueprintCallable)
    void ShowHealthBar();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetState(ECoreCorruptionCrystalState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_ExitedState(ECoreCorruptionCrystalState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_EnteredState(ECoreCorruptionCrystalState NewState);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_State(ECoreCorruptionCrystalState oldState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRep_Pillar();
    
    UFUNCTION(BlueprintCallable)
    void OnPillarSpawned(AActor* pillarSpawned);
    
    UFUNCTION(BlueprintCallable)
    void OnPillarDestroyed(ACoreCorruptionPillar* pillarDestroyed);
    
    UFUNCTION(BlueprintCallable)
    void OnNewHealthSegment(int32 currentSegment, int32 prevSegment);
    
    UFUNCTION(BlueprintCallable)
    void OnExitedKnockbackZone(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnEnteredKnockbackZone(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnDeath(UHealthComponent* HealthComponent, float damageAmount, const FDamageData& DamageData, const TArray<UDamageTag*>& damageTags);
    
    UFUNCTION(BlueprintCallable)
    void OnDamaged(float Damage, const FDamageData& DamageData, bool anyHealthLost);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowPillarSpawnEffects(FVector_NetQuantize pillarStoneLocation);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayKnockbackEffect() const;
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_AddKnockback(FVector_NetQuantize Direction, float force);
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override PURE_VIRTUAL(HasMatchingGameplayTag, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAnyMatchingGameplayTags, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAllMatchingGameplayTags, return false;);
    
    UFUNCTION(BlueprintCallable)
    void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(GetOwnedGameplayTags,);
    
};

