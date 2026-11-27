#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DamageData.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "IRandRange.h"
#include "NotifyMessageReceiver.h"
#include "PLSResource.h"
#include "RandRange.h"
#include "Templates/SubclassOf.h"
#include "InkBug.generated.h"

class AActor;
class AInkCloud;
class AResourceChunk;
class UAnimMontage;
class UEnemyLineOfSightComponent;
class UHealthComponentBase;
class UMaterialInterface;
class UOutlineComponent;
class UResourceData;
class UStatusEffect;

UCLASS(Blueprintable)
class FSD_API AInkBug : public AEnemyDeepPathfinderCharacter, public INotifyMessageReceiver {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyLineOfSightComponent* LineOfSight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOutlineComponent* outline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIRandRange PopChunkCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandRange PopChunkValueRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> PopSpawnActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UResourceData*> AvailableResources;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* deathMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyCamouflage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FleeMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* HideMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReFleeRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FarFleeExtraDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bPlayingFleeMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bFleeTellPlayed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bFarFleeing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector FleeStartLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector PendingFleeLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsCamouflaged, meta=(AllowPrivateAccess=true))
    bool bIsCamouflaged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* CamouflageRenderMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AInkCloud> InkCloudClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> InkCloudSpeedBoost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InkCloudCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InkCloudUntargetableDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool bIsInkCloudUntargetable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInkCloudPending;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInkCloudSpeedBoostPending;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPLSResource> LootChunks;
    
public:
    AInkBug(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUncamouflageBegin(UMaterialInterface* TerrainRenderMaterial);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsCamouflaged();
    
    UFUNCTION(BlueprintCallable)
    void OnHealthHit(float Damage, const FDamageData& DamageData, bool anyHealthLost);
    
    UFUNCTION(BlueprintCallable)
    void OnHealthDeath(UHealthComponentBase* deadHealth);
    
    UFUNCTION(BlueprintCallable)
    void OnFleeMontageEnded(UAnimMontage* Montage, bool interrupted);
    
    UFUNCTION(BlueprintCallable)
    void OnFarFleeFinished(bool success);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDeathMontageFinished();
    
    UFUNCTION(BlueprintCallable)
    void OnDeathMontageBlendingOut(UAnimMontage* Montage, bool interrupted);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCamouflageBegin(UMaterialInterface* TerrainRenderMaterial);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasLoot() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UMaterialInterface* GetCachedMaterial() const;
    
public:
    UFUNCTION(BlueprintCallable)
    AResourceChunk* DropLoot(FVector Impulse, FVector DropOffset);
    
    UFUNCTION(BlueprintCallable)
    AActor* DropItem(FVector Impulse, FVector DropOffset);
    

    // Fix for true pure virtual functions not being implemented
};

