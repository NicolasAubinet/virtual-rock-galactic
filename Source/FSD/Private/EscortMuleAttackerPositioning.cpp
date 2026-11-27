#include "EscortMuleAttackerPositioning.h"

UEscortMuleAttackerPositioning::UEscortMuleAttackerPositioning(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FreePositions.AddDefaulted(32);
    this->FlyingFreePositions.AddDefaulted(32);
    this->Health = NULL;
}

void UEscortMuleAttackerPositioning::SetScoreModifier(float newModifier) {
}

void UEscortMuleAttackerPositioning::SetNewMaxAttackers(int32 newMaxAttackers) {
}


