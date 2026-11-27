#pragma once
#include "CoreMinimal.h"
#include "FloatPerkComponent.h"
#include "SecondChanceRechargeComponent.generated.h"

class UDialogDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USecondChanceRechargeComponent : public UFloatPerkComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* ShoutOnUseRestored;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthThresholdPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float RechargeStartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float RechargeDuration;
    
public:
    USecondChanceRechargeComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void OnHealthChanged(float Health);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRechargeProgress() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void CheckToRestore();
    
};

