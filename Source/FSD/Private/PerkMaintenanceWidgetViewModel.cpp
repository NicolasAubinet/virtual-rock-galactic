#include "PerkMaintenanceWidgetViewModel.h"

FPerkMaintenanceWidgetViewModel::FPerkMaintenanceWidgetViewModel() {
    this->Icon = NULL;
    this->UsageType = EPerkUsageType::Passive;
    this->Progress = 0.00f;
    this->CurrentXP = 0;
    this->MaxXP = 0;
    this->bIsUnlocked = false;
    this->bIsMaxed = false;
    this->bIsEquipped = false;
}

