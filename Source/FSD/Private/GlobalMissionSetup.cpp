#include "GlobalMissionSetup.h"

UGlobalMissionSetup::UGlobalMissionSetup() {
    this->FacilityMutatorChance = 0.25f;
    this->MissionNames = NULL;
    this->DoubleWarningChance = 0.50f;
    this->DoubleWarningStat = NULL;
    this->MysteryMissionWarning = NULL;
    this->MysteryMissionChance = 1.00f;
    this->MysteryMissionMutatorChance = 0.25f;
}

TArray<FMissionTemplateItem> UGlobalMissionSetup::GetAllPossibleMissions() const {
    return TArray<FMissionTemplateItem>();
}


