#pragma once
#include "CoreMinimal.h"
#include "Objective.h"
#include "BatchObjective.generated.h"

class ABatchSubObjective;
class APlayerCharacter;
class UCaveInfluencer;
class UDebrisBase;
class UDebrisPositioning;
class UTerrainMaterial;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UBatchObjective : public UObjective {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SubObjectiveCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ABatchSubObjective>> SubObjectivePool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* Positioning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> ExcludeRoomIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialMinDistanceToOtherObjectives;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FinalMinDistanceToOtherObjectives;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistanceIterationStepAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImportantLocationRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistanceToImportantLocations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCaveInfluencer* CaveInfluencer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DebrisRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftObjectPtr<UDebrisBase>, bool> ObjectDebris;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SubObjectivesCompleted, meta=(AllowPrivateAccess=true))
    int32 SubObjectivesCompleted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SubObjectivesToComplete, meta=(AllowPrivateAccess=true))
    int32 SubObjectivesToComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ABatchSubObjective*> SpawnedSubObjectives;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ABatchSubObjective*> ActiveSubObjectives;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterial* BiomeRockMaterial;
    
public:
    UBatchObjective(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveSubObjectiveCompleted(ABatchSubObjective* SubObjective, APlayerCharacter* instigatingPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveSubObjectiveActivated(ABatchSubObjective* SubObjective, APlayerCharacter* instigatingPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnSubObjectiveCompleted(ABatchSubObjective* SubObjective, APlayerCharacter* instigatingPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnSubObjectiveActivated(ABatchSubObjective* SubObjective, APlayerCharacter* instigatingPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_SubObjectivesToComplete(const int32 prevAmount);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_SubObjectivesCompleted(const int32 prevAmount);
    
};

