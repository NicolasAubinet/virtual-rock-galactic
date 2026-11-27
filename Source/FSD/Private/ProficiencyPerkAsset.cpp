#include "ProficiencyPerkAsset.h"

UProficiencyPerkAsset::UProficiencyPerkAsset() {
    this->Proficiency = EProficiency::NoProficiency;
}

bool UProficiencyPerkAsset::HasUnlockedAllPerks(AFSDPlayerController* Player) {
    return false;
}

float UProficiencyPerkAsset::GetPerkValue(UObject* WorldContext) const {
    return 0.0f;
}

float UProficiencyPerkAsset::GetFloatPerkValue(UObject* WorldContext, UFloatPerkAsset* Perk, float UnclaimedValue) {
    return 0.0f;
}


