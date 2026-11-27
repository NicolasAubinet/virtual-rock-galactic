#pragma once
#include "CoreMinimal.h"
#include "BasicThrowableItem.h"
#include "BreachChargeDetonatedDelegate.h"
#include "EBreachChargeState.h"
#include "BreachCharge.generated.h"

class AActor;

UCLASS(Blueprintable)
class FSD_API ABreachCharge : public ABasicThrowableItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FuseTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DestroyDelayAfterDetonation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HideOnDetonation;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBreachChargeDetonated OnChargeDetonated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EBreachChargeState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    AActor* AttachedTarget;
    
public:
    ABreachCharge(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_State();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDroppedByPlayer();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDetonated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnChargeStateChanged(EBreachChargeState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAttached(AActor* Target);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnArmed(float fuseDuration);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDeployed() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleCarriableDropped();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFuseRemaining() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EBreachChargeState GetChargeState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetAttachedTarget() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Detonate();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AttachToTarget(AActor* Target);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool Arm();
    
};

