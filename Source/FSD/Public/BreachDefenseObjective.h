#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EExtractionDrillState.h"
#include "Objective.h"
#include "RoomNode.h"
#include "Templates/SubclassOf.h"
#include "BreachDefenseObjective.generated.h"

class AActor;
class ABreachCrustTarget;
class AExtractionDrill;
class APlayerCharacter;
class AProceduralSetup;
class UDebrisPositioning;
class UDialogDataAsset;
class UEnemyWaveController;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UBreachDefenseObjective : public UObjective {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugCompleteTargetsOnImpact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugShowCrackPaths;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugShowBreachEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FailMissionOnDrillDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* DrillDestroyedShout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MissionFailDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UEnemyWaveController>> CaveArrivalWaves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ArrivalWaveDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnemyWaveController> FinalDrillingWave;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ABreachCrustTarget*> CrustTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AExtractionDrill* ExtractionDrill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_DrillDestroyed, meta=(AllowPrivateAccess=true))
    bool DrillDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_DrillLaunched, meta=(AllowPrivateAccess=true))
    bool DrillLaunched;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    int32 LostGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UEnemyWaveController*> TriggeredWaves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEnemyWaveController> PendingArrivalWave;
    
public:
    UBreachDefenseObjective(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    UEnemyWaveController* TriggerWave(TSubclassOf<UEnemyWaveController> waveClass);
    
private:
    UFUNCTION(BlueprintCallable)
    void SpawnPendingArrivalWave();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ResumeTriggeredWaves();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RegisterExtractionDrill(AExtractionDrill* drill);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RegisterCrustTarget(ABreachCrustTarget* Target);
    
    UFUNCTION(BlueprintCallable)
    AActor* PlaceObjectInRoom(AProceduralSetup* Setup, const FRoomNode& RoomNode, UDebrisPositioning* Positioning, TSubclassOf<AActor> placementActor, FRandomStream RandomStream, const bool checkImportantLocations);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PauseTriggeredWaves();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_DrillLaunched();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_DrillDestroyed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDrillLaunched();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDrillDestroyed(int32 groupIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCurrentLevelBreached();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDrillDestroyed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentLevelBreached() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasDrillLaunched() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleTargetDestroyed(ABreachCrustTarget* Target);
    
    UFUNCTION(BlueprintCallable)
    void HandleSubstructureLost(int32 groupIndex);
    
    UFUNCTION(BlueprintCallable)
    void HandleDrillStateChanged(EExtractionDrillState NewState);
    
    UFUNCTION(BlueprintCallable)
    void HandleDrillImpacted();
    
    UFUNCTION(BlueprintCallable)
    void HandleDrillDeparted();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTargetCountForCurrentLevel() const;
    
    UFUNCTION(BlueprintCallable)
    void GetObjectTransformInRoom(FTransform& Transform, AProceduralSetup* Setup, const FRoomNode& RoomNode, UDebrisPositioning* Positioning, TSubclassOf<AActor> placementActor, FRandomStream RandomStream, const bool checkImportantLocations);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AExtractionDrill* GetExtractionDrill() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDestroyedTargetCountForCurrentLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetDebugStatus() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void FailMission();
    
public:
    UFUNCTION(BlueprintCallable)
    bool DebugUnblockDrill();
    
    UFUNCTION(BlueprintCallable)
    bool DebugTeleportPlayerToDrill(APlayerCharacter* Player, float offsetBehind);
    
    UFUNCTION(BlueprintCallable)
    bool DebugStartNextDrillPhase();
    
    UFUNCTION(BlueprintCallable)
    int32 DebugShowAllCrackPaths(bool Show);
    
    UFUNCTION(BlueprintCallable)
    bool DebugSetDrillState(EExtractionDrillState NewState);
    
    UFUNCTION(BlueprintCallable)
    bool DebugSetChargeDispenserOpen(bool Open);
    
    UFUNCTION(BlueprintCallable)
    bool DebugLaunchDrill();
    
    UFUNCTION(BlueprintCallable)
    bool DebugFinishFinalDrilling();
    
    UFUNCTION(BlueprintCallable)
    int32 DebugDetonateAllCharges();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DebugCompleteCurrentLevel();
    
    UFUNCTION(BlueprintCallable)
    int32 DebugCompleteAllTargets();
    
};

