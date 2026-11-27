#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "Templates/SubclassOf.h"
#include "CoilgunWeaponTrail.generated.h"

class UCapsuleComponent;
class UDamageComponent;
class UNiagaraComponent;
class UPrimitiveComponent;
class USceneComponent;
class UStatusEffect;

UCLASS(Blueprintable)
class ACoilgunWeaponTrail : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* Collision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* Trail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* DamageComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LightningBoltStartOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LightningBoltDamageRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LightningBoltDamageScaler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool SpanReadyFired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_TrailHalfLength, meta=(AllowPrivateAccess=true))
    float TrailHalgLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SpawnFireTrail, meta=(AllowPrivateAccess=true))
    bool SpawnFireTrail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> FireEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> ElectricEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UStatusEffect>> EffectsToApply;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<AActor*> HitActors;
    
public:
    ACoilgunWeaponTrail(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayLightningBoltExplosion(const FVector& StartLocation, const FVector& EndLocation);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_TrailHalfLength();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_SpawnFireTrail();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnLightningBoltSpanReady(const FVector& StartLocation, const FVector& EndLocation);
    
    UFUNCTION(BlueprintCallable)
    void OnInited_Callback();
    
    UFUNCTION(BlueprintCallable)
    void OnActorLeaveTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnActorEnteredTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetLightningBoltSpan(FVector& OutStart, FVector& OutEnd) const;
    
};

