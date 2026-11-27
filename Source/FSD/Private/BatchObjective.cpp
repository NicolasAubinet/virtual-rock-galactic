#include "BatchObjective.h"
#include "Net/UnrealNetwork.h"

UBatchObjective::UBatchObjective(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SubObjectiveCount = 0;
    this->Positioning = NULL;
    this->InitialMinDistanceToOtherObjectives = 10000.00f;
    this->FinalMinDistanceToOtherObjectives = 5000.00f;
    this->MinDistanceIterationStepAmount = 500.00f;
    this->ImportantLocationRadius = 1000.00f;
    this->MinDistanceToImportantLocations = 750.00f;
    this->CaveInfluencer = NULL;
    this->DebrisRadius = 1500.00f;
    this->SubObjectivesCompleted = 0;
    this->SubObjectivesToComplete = 0;
    this->BiomeRockMaterial = NULL;
}



void UBatchObjective::OnSubObjectiveCompleted(ABatchSubObjective* SubObjective, APlayerCharacter* instigatingPlayer) {
}

void UBatchObjective::OnSubObjectiveActivated(ABatchSubObjective* SubObjective, APlayerCharacter* instigatingPlayer) {
}

void UBatchObjective::OnRep_SubObjectivesToComplete(const int32 prevAmount) {
}

void UBatchObjective::OnRep_SubObjectivesCompleted(const int32 prevAmount) {
}

void UBatchObjective::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UBatchObjective, SubObjectivesCompleted);
    DOREPLIFETIME(UBatchObjective, SubObjectivesToComplete);
}


