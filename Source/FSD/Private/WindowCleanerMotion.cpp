#include "WindowCleanerMotion.h"

FWindowCleanerMotion::FWindowCleanerMotion() {
    this->Column = 0;
    this->TargetColumn = 0;
    this->Phase = EWindowCleanerPhase::Idle;
    this->StartServerTime = 0.00f;
    this->SpeedMultiplier = 0.00f;
}

