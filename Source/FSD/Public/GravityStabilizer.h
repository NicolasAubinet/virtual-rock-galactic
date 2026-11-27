#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "DamageData.h"
#include "FloatingDebrisActor.h"
#include "GravityStabilizerTriggeredSigDelegate.h"
#include "GravityStabilizer.generated.h"

class AActor;
class UDamageComponent;
class UNiagaraComponent;
class UNiagaraSystem;
class UPrimitiveComponent;
class USimpleHealthComponent;
class USphereComponent;

UCLASS(Blueprintable)
class FSD_API AGravityStabilizer : public AFloatingDebrisActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGravityStabilizerTriggeredSig OnStabilizerTriggered;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* RepulseTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* DamageCollider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimpleHealthComponent* HealthComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* RepulseDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RepulseInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* RepulseEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* CooldownEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CooldownDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* CooldownEffectComponent;
    
public:
    AGravityStabilizer(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTriggered();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnRepulse();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOnCooldown() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleRepulseEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void HandleRepulseBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void HandleHit(float Damage, const FDamageData& DamageData, bool bAnyHealthLost);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_StartCooldownEffect();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayRepulseEffect();
    
};

