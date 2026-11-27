#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/NetSerialization.h"
#include "ECharacterState.h"
#include "EPowerBootsChargeChange.h"
#include "PowerBootsChargeState.h"
#include "Templates/SubclassOf.h"
#include "PowerBootsMovementComponent.generated.h"

class APlayerCharacter;
class UAudioComponent;
class UDamageComponent;
class UDoubleJumpEffect;
class UFSDPhysicalMaterial;
class UGroundImpactShockwaveEffect;
class UHealthComponentBase;
class UPawnStat;
class UPowerBootsChargeEffect;
class UPowerBootsChargeWidget;
class UPrimitiveComponent;
class USoundBase;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPowerBootsMovementComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Stage1HoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Stage2HoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Stage3HoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Stage2JumpZVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OverchargeJumpMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Stage1JumpAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinImpactVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamagePerVelocityAboveMinimum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDamageComponent> ShockwaveDamageComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnemyImpactGracePeriod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPawnStat* FallDamageReductionStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FallDamageReduction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AirControlMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LedgeClimbVelocityMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPowerBootsChargeEffect> ChargeEffectClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDoubleJumpEffect> JumpEffectClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGroundImpactShockwaveEffect> ShockwaveEffectClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* ChargeSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* ChargedLoopSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* Stage1LaunchSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* Stage2LaunchSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* OverchargeLaunchSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* ModerateImpactSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* HeavyImpactSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeavyImpactVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChargeDelay;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ChargeState, meta=(AllowPrivateAccess=true))
    FPowerBootsChargeState ChargeState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPowerBootsChargeEffect* ChargeEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPowerBootsChargeWidget* ChargeWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDamageComponent* ShockwaveDamageComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* ChargeAudio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* ChargedLoopAudio;
    
public:
    UPowerBootsMovementComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetChargeStage(uint8 Stage, EPowerBootsChargeChange reason);
    
    UFUNCTION(BlueprintCallable)
    void OnShockwaveTargetDamaged(UHealthComponentBase* Health, float amount, UPrimitiveComponent* Component, UFSDPhysicalMaterial* PhysicalMaterial);
    
    UFUNCTION(BlueprintCallable)
    void OnShockwaveComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ChargeState(FPowerBootsChargeState oldState);
    
    UFUNCTION(BlueprintCallable)
    void OnLanded(const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable)
    void OnJumpReleased();
    
    UFUNCTION(BlueprintCallable)
    void OnJumpPressed();
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterStateChanged(ECharacterState NewState);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowShockwave(const FVector_NetQuantize& Location, const FRotator& Rotation, float ImpactVelocity);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowChargedJump(uint8 Stage);
    
};

