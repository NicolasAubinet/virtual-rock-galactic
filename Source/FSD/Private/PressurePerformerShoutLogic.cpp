#include "PressurePerformerShoutLogic.h"

UPressurePerformerShoutLogic::UPressurePerformerShoutLogic(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ShoutTeammateDown = NULL;
    this->ShoutLastStanding = NULL;
}

void UPressurePerformerShoutLogic::OnAnyDwarfDied() {
}


