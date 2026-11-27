#include "WindowCleanerButton.h"

UWindowCleanerButton::UWindowCleanerButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->IsClientPredictive = true;
    this->Command = EWindowCleanerCommand::Left;
}


