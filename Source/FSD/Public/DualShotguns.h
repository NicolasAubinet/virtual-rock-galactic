#pragma once
#include "CoreMinimal.h"
#include "AltFireMode.h"
#include "DualWieldWeapon.h"
#include "FireModeChangedDelegateDelegate.h"
#include "DualShotguns.generated.h"

class UFXSystemAsset;
class USoundCue;

UCLASS(Abstract, Blueprintable)
class FSD_API ADualShotguns : public ADualWieldWeapon {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFireModeChangedDelegate OnFireModeChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FireModeSwitchTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SwitchingFireMode, meta=(AllowPrivateAccess=true))
    bool bSwitchingFireMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAltFireMode AltFireMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* MuzzleParticles_AltFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* TPMuzzleParticles_AltFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* FireSound_AltFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* MuzzleParticles_BaseFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* TPMuzzleParticles_BaseFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* FireSound_BaseFire;
    
public:
    ADualShotguns(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_BeginSwitchFireMode();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_BeginSwitchFireMode(bool bToAltFireMode);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_SwitchingFireMode();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_SwitchFireModeCompleted();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_BeginSwitchFireMode(bool bToAltFireMode);
    
};

