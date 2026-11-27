#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BreachVentDelegateDelegate.h"
#include "EBreachVentState.h"
#include "EInputKeys.h"
#include "TargetDummyPawn.h"
#include "BreachDrillVent.generated.h"

class APlayerCharacter;
class UBreachVentHealthComponent;
class UContinuousUsableComponent;
class UHealthComponentBase;
class UObjectAttackerPositioning;
class UPointLightComponent;
class USimpleObjectInfoComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class FSD_API ABreachDrillVent : public ATargetDummyPawn {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBreachVentDelegate OnVentBroken;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBreachVentDelegate OnVentRepaired;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetCenterOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* VentMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBreachVentHealthComponent* Health;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPointLightComponent* VentLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimpleObjectInfoComponent* ObjectInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObjectAttackerPositioning* AttackerPositioning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RepairUsableTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RepairIdleTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RepairPerTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    int32 VentGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Repairing, meta=(AllowPrivateAccess=true))
    bool Repairing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugStartVulnerable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugAutoDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DebugAutoDamageAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DebugAutoDamageInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EBreachVentState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_VentOpen, meta=(AllowPrivateAccess=true))
    bool VentOpen;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UContinuousUsableComponent*> RepairUsables;
    
public:
    ABreachDrillVent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void TickDebugDamage();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetVulnerable(bool vulnerable);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetVentGroup(int32 groupIndex);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool Repair(float amount);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnVentStateChanged(EBreachVentState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnVentRepairingChanged(bool isRepairing);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnVentingChanged(bool IsVenting);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnVentDamaged(float healthFraction);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRepairTick(APlayerCharacter* User, EInputKeys Key);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_VentOpen();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_State();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_Repairing();
    
    UFUNCTION(BlueprintCallable)
    void OnHealthChanged(float newHealth);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDebugPlayerReady(APlayerCharacter* PlayerCharacter);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnDeath(UHealthComponentBase* HealthComponent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOpen() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBroken() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleDebugPlayerSpawned(APlayerCharacter* PlayerCharacter);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EBreachVentState GetVentState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetVentGroup() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealthFraction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBreachVentHealthComponent* GetHealth() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void EndRepairing();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DebugSetAutoDamage(bool Enabled);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanBeRepaired() const;
    
};

