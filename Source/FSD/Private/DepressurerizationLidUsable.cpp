#include "DepressurerizationLidUsable.h"

UDepressurerizationLidUsable::UDepressurerizationLidUsable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->IsClientPredictive = true;
    this->Usable = true;
    this->OpenText = FText::FromString(TEXT("Open Cover"));
    this->CloseText = FText::FromString(TEXT("Close Cover"));
}


