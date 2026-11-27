#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "BreachCrustTargetDestroyedDelegate.h"
#include "EInputKeys.h"
#include "Templates/SubclassOf.h"
#include "BreachCrustTarget.generated.h"

class ABreachCharge;
class ABreachChargeBeacon;
class ABreachCrustCrack;
class APlayerCharacter;
class UInstantUsable;
class USingleUsableComponent;

UCLASS(Blueprintable)
class FSD_API ABreachCrustTarget : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 LevelIndex;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBreachCrustTargetDestroyed OnTargetDestroyed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachUsableTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ArmUsableTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ChargeAttachOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ABreachChargeBeacon> BeaconClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector BeaconOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ABreachCrustCrack> CrackClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CrackSpawnOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugShowMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DebugSphereRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DebugBeamHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DebugLineThickness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ABreachChargeBeacon* Beacon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_AttachedCharge, meta=(AllowPrivateAccess=true))
    ABreachCharge* AttachedCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Destroyed, meta=(AllowPrivateAccess=true))
    bool Destroyed;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UInstantUsable*> AttachUsables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USingleUsableComponent*> ArmUsables;
    
public:
    ABreachCrustTarget(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetDebugShowCrackPath(bool Show);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Destroyed();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_AttachedCharge();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDestroyedByCharge();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnChargeDetonated(ABreachCharge* charge);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnChargeAttached(ABreachCharge* charge);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnAttachUsed(APlayerCharacter* User, EInputKeys Key);
    
    UFUNCTION(BlueprintCallable)
    void OnArmUsed(APlayerCharacter* User, EInputKeys Key);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void NotifyDestroyed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDestroyed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasCharge() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ABreachCharge* GetAttachedCharge() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AttachCharge(ABreachCharge* charge);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool ArmCharge();
    
};

