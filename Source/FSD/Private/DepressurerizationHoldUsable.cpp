#include "DepressurerizationHoldUsable.h"

UDepressurerizationHoldUsable::UDepressurerizationHoldUsable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UseText = FText::FromString(TEXT("Depressurerize"));
    this->ResetOnFail = true;
    this->TurnOffAfterUse = true;
}


