#include "CoreCorruptionObjective.h"
#include "Net/UnrealNetwork.h"

UCoreCorruptionObjective::UCoreCorruptionObjective(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OverridePrimaryObjCompletedShout_SelfCompleted = NULL;
    this->OverridePrimaryObjCompletedShout_SelfNotCompleted = NULL;
    this->SpawnedCoreStone = NULL;
    this->bCoreStoneDefeated = false;
}

void UCoreCorruptionObjective::SetCoreStoneDefeated() {
}

void UCoreCorruptionObjective::OnRep_CoreStoneDefeated() {
}

void UCoreCorruptionObjective::OnCoreStoneDeath(UHealthComponentBase* Health) {
}

void UCoreCorruptionObjective::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UCoreCorruptionObjective, bCoreStoneDefeated);
}


