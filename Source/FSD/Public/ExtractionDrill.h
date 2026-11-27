#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EExtractionDrillState.h"
#include "ExtractionDrillDepartedDelegateDelegate.h"
#include "ExtractionDrillImpactDelegateDelegate.h"
#include "ExtractionDrillStateDelegateDelegate.h"
#include "ExtractionDrillSubstructureDelegateDelegate.h"
#include "TaggedActor.h"
#include "Templates/SubclassOf.h"
#include "ExtractionDrill.generated.h"

class AActor;
class ABreachDrillVent;
class AExtractionDrill;
class AExtractionDrillElevator;
class AItemDispenser;
class UAutoCarverComponent;
class UCurveFloat;
class UExtractionDrillWidget;
class UObject;
class UPathfinderCollisionComponent;
class UResourceBank;
class USceneComponent;
class USingleUsableComponent;
class USpotLightComponent;
class UWidgetComponent;

UCLASS(Blueprintable)
class FSD_API AExtractionDrill : public ATaggedActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DropHeight;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExtractionDrillSubstructureDelegate OnSubstructureLost;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExtractionDrillStateDelegate OnDrillStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExtractionDrillImpactDelegate OnDrillImpacted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExtractionDrillDepartedDelegate OnDrillDeparted;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FVector TargetLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UResourceBank* ResourceBank;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DepartureTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector StartLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EExtractionDrillState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DrillSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DrillWarmupTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* DescentCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReadySinkDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReadySinkDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FinalDrillDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FinalDrillingDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VentingDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugSkipVenting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugSkipBreachTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugNoTerrain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DebugStopCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DebugDescentDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DebugPhaseDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DrillComponentTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RotatingComponentTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DrillButtonComponentTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LaunchButtonComponentTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AExtractionDrillElevator> ShaftElevatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ShaftElevatorAnchorComponentTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AExtractionDrillElevator> ElevatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ElevatorComponentTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AttachElevatorsToDrill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PathfinderComponentTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItemDispenser> ChargeDispenserClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ChargeDispenserComponentTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ABreachDrillVent> VentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VentComponentTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ActiveVentGroupCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VentGroupRotationInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> VentGroupTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StallDrillingWhenVentBroken;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OpenDispenserWhileBlocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WarningLightYawSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WarningLightYawSpacing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpotLightComponentTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WidgetComponentTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugShowStateText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HardMaterialProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BreakThroughProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarverJitterMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarverJitterMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAutoCarverComponent*> DrillCarvers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> DrillRotators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USingleUsableComponent*> DrillButtons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USingleUsableComponent*> LaunchButtons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPathfinderCollisionComponent*> PathfinderColliders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* WarningLightRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USpotLightComponent*> WarningLights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TArray<ABreachDrillVent*> Vents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TArray<AExtractionDrillElevator*> Elevators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TArray<AExtractionDrillElevator*> ShaftElevators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    AItemDispenser* ChargeDispenser;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USpotLightComponent*> DebugSpotLights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UWidgetComponent*> DrillWidgetComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    int32 DebugTargetsDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    int32 DebugTargetsRequired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FVector DescentStartLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float DescentStartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float DescentDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FVector> DrillStopLocations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 NextDrillStop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_LostSubstructure, meta=(AllowPrivateAccess=true))
    int32 LostSubstructure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> RegisteredStateListeners;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UExtractionDrillWidget*> InitializedWidgets;
    
public:
    AExtractionDrill(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UpdateLaunchButton();
    
    UFUNCTION(BlueprintCallable)
    void UpdateDrillButton();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StartNextDrillPhase();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StartFinalDrilling();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StartEntering();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool StartDrillingToNextStop();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StartDrilling(const FVector& stopLocation);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StartDeparture();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetSpotLightColor(EExtractionDrillState NewState);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetReady();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetDrillStops(const TArray<FVector>& stopLocations);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetChargeDispenserOpen(bool Open);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetBreachProgress(int32 destroyedTargets, int32 requiredTargets);
    
    UFUNCTION(BlueprintCallable)
    void RegisterStateListener(AActor* listener);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnWarmupStarted(float warmupDuration);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnVentingStarted(float VentDuration);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStateChanged(EExtractionDrillState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRepairsFinished();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_State();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_LostSubstructure();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPrepForTakeOff();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinalDrillingStarted(float Duration);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinalDrillingFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnteringStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnteredHardMaterial();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDrillSank();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDrillingStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDrillImpact();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDrillHeadStopped();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDrillHeadStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDrillDestroyed(int32 groupIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDepartureFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDeparting(float departureDuration);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBrokeThrough();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAwaitingRepairs();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsVentGroupVulnerable(int32 groupIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSubstructureLost(int32 groupIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDrillingComplete() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDrillHeadSpinning() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDrillDestroyed() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCarving() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasRemainingDrillStops() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasDeparted() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasBrokenVent() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleVentRepaired(ABreachDrillVent* vent);
    
    UFUNCTION(BlueprintCallable)
    void HandleVentBroken(ABreachDrillVent* vent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ABreachDrillVent*> GetVents() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetLostSubstructure() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AExtractionDrillElevator*> GetElevators() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EExtractionDrillState GetDrillState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentLevelIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AItemDispenser* GetChargeDispenser() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void FinishDeparture();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static AExtractionDrill* DropExtractionDrillToMission(UObject* WorldContextObject, TSubclassOf<AExtractionDrill> drillClass, const FVector& Location);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DebugSetState(EExtractionDrillState NewState);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DebugDeploy();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanUseLaunchButton() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanUseDrillButton() const;
    
};

