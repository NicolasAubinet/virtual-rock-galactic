#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EBreachBeaconState.h"
#include "EInputKeys.h"
#include "ERessuplyPodState.h"
#include "Templates/SubclassOf.h"
#include "BreachChargeBeacon.generated.h"

class ABreachCrustTarget;
class APlayerCharacter;
class ARessuplyPod;
class USingleUsableComponent;

UCLASS(Blueprintable)
class FSD_API ABreachChargeBeacon : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ARessuplyPod> ChargePodClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CalldownUsableTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxGroundAdjustment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EBreachBeaconState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ARessuplyPod* Pod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ABreachCrustTarget* CrustTarget;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USingleUsableComponent*> CalldownUsables;
    
public:
    ABreachChargeBeacon(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetCrustTarget(ABreachCrustTarget* Target);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_State();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPodStateChanged(ARessuplyPod* changedPod, ERessuplyPodState NewState);
    
    UFUNCTION(BlueprintCallable)
    void OnCalldownUsed(APlayerCharacter* User, EInputKeys Key);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeaconStateChanged(EBreachBeaconState NewState);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARessuplyPod* GetPod() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ABreachCrustTarget* GetCrustTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EBreachBeaconState GetBeaconState() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool CallDownPod();
    
};

