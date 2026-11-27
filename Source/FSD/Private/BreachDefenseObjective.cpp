#include "BreachDefenseObjective.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

UBreachDefenseObjective::UBreachDefenseObjective(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DebugCompleteTargetsOnImpact = false;
    this->DebugShowCrackPaths = false;
    this->DebugShowBreachEvents = false;
    this->FailMissionOnDrillDestroyed = true;
    this->DrillDestroyedShout = NULL;
    this->MissionFailDelay = 4.00f;
    this->ArrivalWaveDelay = 5.00f;
    this->FinalDrillingWave = NULL;
    this->ExtractionDrill = NULL;
    this->DrillDestroyed = false;
    this->DrillLaunched = false;
    this->LostGroup = -1;
    this->PendingArrivalWave = NULL;
}

UEnemyWaveController* UBreachDefenseObjective::TriggerWave(TSubclassOf<UEnemyWaveController> waveClass) {
    return NULL;
}

void UBreachDefenseObjective::SpawnPendingArrivalWave() {
}

void UBreachDefenseObjective::ResumeTriggeredWaves() {
}

void UBreachDefenseObjective::RegisterExtractionDrill(AExtractionDrill* drill) {
}

void UBreachDefenseObjective::RegisterCrustTarget(ABreachCrustTarget* Target) {
}

AActor* UBreachDefenseObjective::PlaceObjectInRoom(AProceduralSetup* Setup, const FRoomNode& RoomNode, UDebrisPositioning* Positioning, TSubclassOf<AActor> placementActor, FRandomStream RandomStream, const bool checkImportantLocations) {
    return NULL;
}

void UBreachDefenseObjective::PauseTriggeredWaves() {
}

void UBreachDefenseObjective::OnRep_DrillLaunched() {
}

void UBreachDefenseObjective::OnRep_DrillDestroyed() {
}




bool UBreachDefenseObjective::IsDrillDestroyed() const {
    return false;
}

bool UBreachDefenseObjective::IsCurrentLevelBreached() const {
    return false;
}

bool UBreachDefenseObjective::HasDrillLaunched() const {
    return false;
}

void UBreachDefenseObjective::HandleTargetDestroyed(ABreachCrustTarget* Target) {
}

void UBreachDefenseObjective::HandleSubstructureLost(int32 groupIndex) {
}

void UBreachDefenseObjective::HandleDrillStateChanged(EExtractionDrillState NewState) {
}

void UBreachDefenseObjective::HandleDrillImpacted() {
}

void UBreachDefenseObjective::HandleDrillDeparted() {
}

int32 UBreachDefenseObjective::GetTargetCountForCurrentLevel() const {
    return 0;
}

void UBreachDefenseObjective::GetObjectTransformInRoom(FTransform& Transform, AProceduralSetup* Setup, const FRoomNode& RoomNode, UDebrisPositioning* Positioning, TSubclassOf<AActor> placementActor, FRandomStream RandomStream, const bool checkImportantLocations) {
}

AExtractionDrill* UBreachDefenseObjective::GetExtractionDrill() const {
    return NULL;
}

int32 UBreachDefenseObjective::GetDestroyedTargetCountForCurrentLevel() const {
    return 0;
}

FString UBreachDefenseObjective::GetDebugStatus() const {
    return TEXT("");
}

void UBreachDefenseObjective::FailMission() {
}

bool UBreachDefenseObjective::DebugUnblockDrill() {
    return false;
}

bool UBreachDefenseObjective::DebugTeleportPlayerToDrill(APlayerCharacter* Player, float offsetBehind) {
    return false;
}

bool UBreachDefenseObjective::DebugStartNextDrillPhase() {
    return false;
}

int32 UBreachDefenseObjective::DebugShowAllCrackPaths(bool Show) {
    return 0;
}

bool UBreachDefenseObjective::DebugSetDrillState(EExtractionDrillState NewState) {
    return false;
}

bool UBreachDefenseObjective::DebugSetChargeDispenserOpen(bool Open) {
    return false;
}

bool UBreachDefenseObjective::DebugLaunchDrill() {
    return false;
}

bool UBreachDefenseObjective::DebugFinishFinalDrilling() {
    return false;
}

int32 UBreachDefenseObjective::DebugDetonateAllCharges() {
    return 0;
}

void UBreachDefenseObjective::DebugCompleteCurrentLevel() {
}

int32 UBreachDefenseObjective::DebugCompleteAllTargets() {
    return 0;
}

void UBreachDefenseObjective::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UBreachDefenseObjective, DrillDestroyed);
    DOREPLIFETIME(UBreachDefenseObjective, DrillLaunched);
    DOREPLIFETIME(UBreachDefenseObjective, LostGroup);
}


