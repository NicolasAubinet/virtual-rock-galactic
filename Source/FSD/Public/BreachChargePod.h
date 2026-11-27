#pragma once
#include "CoreMinimal.h"
#include "EBreachChargePodState.h"
#include "EInputKeys.h"
#include "ERessuplyPodState.h"
#include "RessuplyPod.h"
#include "BreachChargePod.generated.h"

class ABreachCrustTarget;
class APlayerCharacter;
class USingleUsableComponent;

UCLASS(Blueprintable)
class FSD_API ABreachChargePod : public ARessuplyPod {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FuseTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DestroyDelayAfterDetonation;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ArmUsableTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ChargeState, meta=(AllowPrivateAccess=true))
    EBreachChargePodState ChargeState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ABreachCrustTarget* CrustTarget;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USingleUsableComponent*> ArmUsables;
    
public:
    ABreachChargePod(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetCrustTarget(ABreachCrustTarget* Target);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_ChargeState();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPodStateChanged(ARessuplyPod* changedPod, ERessuplyPodState NewState);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDetonated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnChargeStateChanged(EBreachChargePodState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnChargeLanded();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnArmUsed(APlayerCharacter* User, EInputKeys Key);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnArmed(float fuseDuration);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFuseRemaining() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ABreachCrustTarget* GetCrustTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EBreachChargePodState GetChargeState() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Detonate();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool Arm();
    
};

