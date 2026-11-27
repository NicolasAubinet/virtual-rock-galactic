#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "EDepressurerizationLidState.h"
#include "EInputKeys.h"
#include "Templates/SubclassOf.h"
#include "UsedBySignatureDelegate.h"
#include "DepressurerizationButton.generated.h"

class APlayerCharacter;
class ASpaceRigBlastShield;
class UAudioComponent;
class UBoxComponent;
class UDepressurerizationHoldUsable;
class UDepressurerizationLidUsable;
class UDialogDataAsset;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class USceneComponent;
class USoundCue;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class FSD_API ADepressurerizationButton : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUsedBySignature OnActivated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* BaseMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* LidMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ProgressMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* WarningLamps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* WarningLamp_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* WarningLamp_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* WarningLamp_3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* WarningLamp_4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* LidCollider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* ButtonCollider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDepressurerizationLidUsable* LidUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDepressurerizationHoldUsable* ButtonUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator LidOpenRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LidFlipDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LidOvershoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLidCanBeClosed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VentDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* LidFirstOpenedShout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* VentStartedShout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VentStartedShoutDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* VentStoppedShout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VentShoutDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* VentPostProcessMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VentPostProcessID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VentIntensityParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VentPulseParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VentFadeDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASpaceRigBlastShield> BlastShieldClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlastShieldCloseDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlastShieldOpenDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* AudioLidOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* AudioLidClose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* AudioHold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* AudioActivated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugAllowRepeatActivation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* ProgressMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ProgressParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LampPowerDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LampPowerParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LampPowerOff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LampPowerOn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LampPowerVentMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LampVentBlinkRate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_LidOpen, meta=(AllowPrivateAccess=true))
    bool bLidOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Activated, meta=(AllowPrivateAccess=true))
    bool bActivated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_VentActive, meta=(AllowPrivateAccess=true))
    bool bVentActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASpaceRigBlastShield* BlastShield;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* ProgressMID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> LampMIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* VentPostProcessMID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* HoldAudioInstance;
    
public:
    ADepressurerizationButton(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetLidOpen(bool bOpen);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ResetActivation();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_VentActive();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_LidOpen();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Activated();
    
    UFUNCTION(BlueprintCallable)
    void OnButtonUserCountChanged(int32 userCount);
    
    UFUNCTION(BlueprintCallable)
    void OnButtonUseEnded();
    
    UFUNCTION(BlueprintCallable)
    void OnButtonProgress(float Progress);
    
    UFUNCTION(BlueprintCallable)
    void OnButtonHoldCompleted(APlayerCharacter* User, EInputKeys Key);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsVenting() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSpent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLidOpen() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EDepressurerizationLidState GetLidState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASpaceRigBlastShield* GetBlastShield() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnVentStopped();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnVentStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnLidStateChanged(EDepressurerizationLidState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnLidOpened();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnLidClosed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnLampsPowerChanging(bool bPoweringUp);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnLampsPower(float Power);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnLampsFullyLit();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnLampsBlink(bool bOn);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnLampLit(int32 LampIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnHoldStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnHoldProgress(float Progress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnHoldCancelled();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnActivated(APlayerCharacter* User);
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_HoldCancelled();
    
};

