#pragma once
#include "CoreMinimal.h"
#include "Objective.h"
#include "CoreCorruptionObjective.generated.h"

class ACoreCorruptionCrystal;
class UDialogDataAsset;
class UHealthComponentBase;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UCoreCorruptionObjective : public UObjective {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* OverridePrimaryObjCompletedShout_SelfCompleted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* OverridePrimaryObjCompletedShout_SelfNotCompleted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACoreCorruptionCrystal* SpawnedCoreStone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CoreStoneDefeated, meta=(AllowPrivateAccess=true))
    bool bCoreStoneDefeated;
    
public:
    UCoreCorruptionObjective(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetCoreStoneDefeated();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_CoreStoneDefeated();
    
    UFUNCTION(BlueprintCallable)
    void OnCoreStoneDeath(UHealthComponentBase* Health);
    
};

