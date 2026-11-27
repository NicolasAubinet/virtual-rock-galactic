#include "PowerBootsChargeState.h"

FPowerBootsChargeState::FPowerBootsChargeState() {
    this->Stage = 0;
    this->reason = EPowerBootsChargeChange::Charged;
}

