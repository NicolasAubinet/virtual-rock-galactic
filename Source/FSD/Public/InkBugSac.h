#pragma once
#include "CoreMinimal.h"
#include "EInputKeys.h"
#include "FSDPhysicsActor.h"
#include "Templates/SubclassOf.h"
#include "TreasureWeight.h"
#include "InkBugSac.generated.h"

class APlayerCharacter;
class UBoxComponent;
class UInstantUsable;
class UItemAquisitionSource;
class URotatingSceneComponent;
class UStatusEffect;
class UTreasureRewarder;

UCLASS(Blueprintable)
class FSD_API AInkBugSac : public AFSDPhysicsActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* CollisionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstantUsable* CollectUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URotatingSceneComponent* HologramAnchor;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTreasureWeight> PossibleRewarders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemAquisitionSource* AquisitionSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RewardGrantDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LifespanAfterGrant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CrushDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> CrushStatusEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTreasureRewarder* rewarder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Collected, meta=(AllowPrivateAccess=true))
    bool bCollected;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Claimer;
    
public:
    AInkBugSac(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRewardGranted();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Collected();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnItemCollected();
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleUsedBy(APlayerCharacter* User, EInputKeys Key);
    
    UFUNCTION(BlueprintCallable)
    void GrantRewards();
    
};

