#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "AmmoDrivenWeapon.h"
#include "ChargeChangedDelegateDelegate.h"
#include "EFissionChargeState.h"
#include "FissionVentItem.generated.h"

class UAnimMontage;
class UDamageComponent;
class UDamageTag;
class UFSDAudioComponent;
class UParticleSystem;
class UParticleSystemComponent;

UCLASS(Abstract, Blueprintable)
class FSD_API AFissionVentItem : public AAmmoDrivenWeapon {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChargeChangedDelegate OnChargeChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* Damage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ChargeState, meta=(AllowPrivateAccess=true))
    EFissionChargeState ChargeState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WindUpRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WindUpMeterFraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float WindUpProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bWindUpComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Remote_ChargeUpProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LastBroadcastChargeMeter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 AmmoBanked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float AmmoToBankNextTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BaseChargeAmmoCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxChargeAmmoCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AmmoConsumptionRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxChargeShotPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxChargeAngleMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageTag* MaxChargeDamageTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* WeaponOverheatAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FP_ChargeupMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* TP_ChargeupMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* WindUpParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* ChargeupParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* FullChargeParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* CooldownParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* OverheatParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* WindUpParticleInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* ChargeupParticleInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* FullChargeParticleInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* CooldownParticleInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* OverheatParticleInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFSDAudioComponent* WindUpAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFSDAudioComponent* ChargeUpAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFSDAudioComponent* FireAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float TotalHeat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolingRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeatPerSecondWhileCharging;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeatPerSecondWhenCharged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeatPerBaseChargeShot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeatPerMaxChargeShot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve WindUpLightIntensityCurve;
    
public:
    AFissionVentItem(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetChargeState(EFissionChargeState NewState);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ActivateMaxChargeDamageTag(bool isMaxCharge);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveWindUpProgressChanged(float NewWindUpProgress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveOverheatedChanged(bool isOverheated);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveChargeProgressChanged(float NewChargeProgress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveChargeMeterChanged(float amount);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveChargedShotFired(float ChargeAmount);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnWindUpStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnWindUpEnded();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_ChargeState(EFissionChargeState oldState);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFullyChargedEnded();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFullyCharged();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnChargeStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnChargeEnded();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsWindingUp() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsFullyCharged() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsCharging() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EFissionChargeState GetChargeState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetChargeMeter() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetChargedShotPower() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetChargedHalfAngleMultiplier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBaseConeHalfAngle() const;
    
};

