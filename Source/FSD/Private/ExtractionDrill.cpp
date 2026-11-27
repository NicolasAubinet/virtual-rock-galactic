#include "ExtractionDrill.h"
#include "Components/SceneComponent.h"
#include "Net/UnrealNetwork.h"
#include "ResourceBank.h"
#include "Templates/SubclassOf.h"

AExtractionDrill::AExtractionDrill(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->DropHeight = 3500.00f;
    this->ResourceBank = CreateDefaultSubobject<UResourceBank>(TEXT("ResourceBank"));
    this->DepartureTime = 12.00f;
    this->State = EExtractionDrillState::WaitingToEnter;
    this->DrillSpeed = 500.00f;
    this->DrillWarmupTime = 5.00f;
    this->DescentCurve = NULL;
    this->ReadySinkDepth = 100.00f;
    this->ReadySinkDuration = 1.50f;
    this->FinalDrillDepth = 1000.00f;
    this->FinalDrillingDuration = 60.00f;
    this->VentingDuration = 60.00f;
    this->DebugSkipVenting = false;
    this->DebugSkipBreachTargets = false;
    this->DebugNoTerrain = false;
    this->DebugStopCount = 2;
    this->DebugDescentDuration = 4.00f;
    this->DebugPhaseDuration = 5.00f;
    this->DrillComponentTag = TEXT("drill");
    this->RotatingComponentTag = TEXT("Rotating");
    this->DrillButtonComponentTag = TEXT("drillButton");
    this->LaunchButtonComponentTag = TEXT("LaunchButton");
    this->ShaftElevatorClass = NULL;
    this->ShaftElevatorAnchorComponentTag = TEXT("ShaftElevator");
    this->ElevatorClass = NULL;
    this->ElevatorComponentTag = TEXT("Elevator");
    this->AttachElevatorsToDrill = true;
    this->PathfinderComponentTag = TEXT("Pathfinder");
    this->ChargeDispenserClass = NULL;
    this->ChargeDispenserComponentTag = TEXT("ChargeDispenser");
    this->VentClass = NULL;
    this->VentComponentTag = TEXT("vent");
    this->ActiveVentGroupCount = 1;
    this->VentGroupRotationInterval = 15.00f;
    this->VentGroupTags.AddDefaulted(3);
    this->StallDrillingWhenVentBroken = false;
    this->OpenDispenserWhileBlocked = true;
    this->WarningLightYawSpeed = 240.00f;
    this->WarningLightYawSpacing = 120.00f;
    this->SpotLightComponentTag = TEXT("SpotLight");
    this->WidgetComponentTag = TEXT("DrillWidget");
    this->DebugShowStateText = false;
    this->HardMaterialProgress = 0.15f;
    this->BreakThroughProgress = 0.85f;
    this->CarverJitterMin = 1.00f;
    this->CarverJitterMax = 1.01f;
    this->Root = (USceneComponent*)RootComponent;
    this->WarningLightRoot = CreateDefaultSubobject<USceneComponent>(TEXT("WarningLightRoot"));
    this->WarningLights.AddDefaulted(3);
    this->ChargeDispenser = NULL;
    this->DebugTargetsDestroyed = 0;
    this->DebugTargetsRequired = 0;
    this->DescentStartTime = 0.00f;
    this->DescentDuration = 0.00f;
    this->NextDrillStop = 0;
    this->LostSubstructure = -1;
    this->WarningLightRoot->SetupAttachment(RootComponent);
}

void AExtractionDrill::UpdateLaunchButton() {
}

void AExtractionDrill::UpdateDrillButton() {
}

void AExtractionDrill::StartNextDrillPhase() {
}

void AExtractionDrill::StartFinalDrilling() {
}

void AExtractionDrill::StartEntering() {
}

bool AExtractionDrill::StartDrillingToNextStop() {
    return false;
}

void AExtractionDrill::StartDrilling(const FVector& stopLocation) {
}

void AExtractionDrill::StartDeparture() {
}

void AExtractionDrill::SetSpotLightColor_Implementation(EExtractionDrillState NewState) {
}

void AExtractionDrill::SetReady() {
}

void AExtractionDrill::SetDrillStops(const TArray<FVector>& stopLocations) {
}

void AExtractionDrill::SetChargeDispenserOpen(bool Open) {
}

void AExtractionDrill::SetBreachProgress(int32 destroyedTargets, int32 requiredTargets) {
}

void AExtractionDrill::RegisterStateListener(AActor* listener) {
}





void AExtractionDrill::OnRep_State() {
}

void AExtractionDrill::OnRep_LostSubstructure() {
}
















bool AExtractionDrill::IsVentGroupVulnerable(int32 groupIndex) const {
    return false;
}

bool AExtractionDrill::IsSubstructureLost(int32 groupIndex) const {
    return false;
}

bool AExtractionDrill::IsDrillingComplete() const {
    return false;
}

bool AExtractionDrill::IsDrillHeadSpinning() const {
    return false;
}

bool AExtractionDrill::IsDrillDestroyed() const {
    return false;
}

bool AExtractionDrill::IsCarving() const {
    return false;
}

bool AExtractionDrill::HasRemainingDrillStops() const {
    return false;
}

bool AExtractionDrill::HasDeparted() const {
    return false;
}

bool AExtractionDrill::HasBrokenVent() const {
    return false;
}

void AExtractionDrill::HandleVentRepaired(ABreachDrillVent* vent) {
}

void AExtractionDrill::HandleVentBroken(ABreachDrillVent* vent) {
}

TArray<ABreachDrillVent*> AExtractionDrill::GetVents() const {
    return TArray<ABreachDrillVent*>();
}

int32 AExtractionDrill::GetLostSubstructure() const {
    return 0;
}

TArray<AExtractionDrillElevator*> AExtractionDrill::GetElevators() const {
    return TArray<AExtractionDrillElevator*>();
}

EExtractionDrillState AExtractionDrill::GetDrillState() const {
    return EExtractionDrillState::WaitingToEnter;
}

int32 AExtractionDrill::GetCurrentLevelIndex() const {
    return 0;
}

AItemDispenser* AExtractionDrill::GetChargeDispenser() const {
    return NULL;
}

void AExtractionDrill::FinishDeparture() {
}

AExtractionDrill* AExtractionDrill::DropExtractionDrillToMission(UObject* WorldContextObject, TSubclassOf<AExtractionDrill> drillClass, const FVector& Location) {
    return NULL;
}

void AExtractionDrill::DebugSetState(EExtractionDrillState NewState) {
}

void AExtractionDrill::DebugDeploy() {
}

bool AExtractionDrill::CanUseLaunchButton() const {
    return false;
}

bool AExtractionDrill::CanUseDrillButton() const {
    return false;
}

void AExtractionDrill::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AExtractionDrill, TargetLocation);
    DOREPLIFETIME(AExtractionDrill, State);
    DOREPLIFETIME(AExtractionDrill, Vents);
    DOREPLIFETIME(AExtractionDrill, Elevators);
    DOREPLIFETIME(AExtractionDrill, ShaftElevators);
    DOREPLIFETIME(AExtractionDrill, ChargeDispenser);
    DOREPLIFETIME(AExtractionDrill, DebugTargetsDestroyed);
    DOREPLIFETIME(AExtractionDrill, DebugTargetsRequired);
    DOREPLIFETIME(AExtractionDrill, DescentStartLocation);
    DOREPLIFETIME(AExtractionDrill, DescentStartTime);
    DOREPLIFETIME(AExtractionDrill, DescentDuration);
    DOREPLIFETIME(AExtractionDrill, LostSubstructure);
}


