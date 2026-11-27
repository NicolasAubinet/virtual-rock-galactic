#include "PerkMaintenanceRewardViewModel.h"

FPerkMaintenanceRewardViewModel::FPerkMaintenanceRewardViewModel() {
    this->Character = NULL;
    this->TraversalTool = NULL;
    this->Skin = NULL;
    this->UnlockedSkinCount = 0;
    this->TotalSkinCount = 0;
    this->bIsUnlocked = false;
    this->bCanUnlock = false;
}

