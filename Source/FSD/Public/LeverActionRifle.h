#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "ItemAnimationItem.h"
#include "LARFinisherAnim.h"
#include "LeverActionRifle.generated.h"

class UAnimMontage;
class UProjectileLauncherComponent;

UCLASS(Abstract, Blueprintable)
class ALeverActionRifle : public AAmmoDrivenWeapon {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProjectileLauncherComponent* projectileLauncher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLARFinisherAnim InterruptReload;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLARFinisherAnim CompleteReload;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FinisherDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemAnimationItem GunslingSuccess;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GunslingWindowMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GunslingWindowMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GunslingSuccessWindowMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GunslingSuccessWindowMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GunslingBlendOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IdleBonusThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IdleAccuracyBonusAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIdleAccuracyBonusIsPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IdleDamageBonusAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIdleDamageBonusIsPercentage;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* ActiveGunslingMontage;
    
public:
    ALeverActionRifle(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_StartFinisher(bool bIsComplete);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_GunslingSuccess();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void Multicast_PlayFinisher(bool bIsComplete);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void Multicast_GunslingSuccess();
    
};

