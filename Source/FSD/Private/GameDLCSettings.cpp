#include "GameDLCSettings.h"

UGameDLCSettings::UGameDLCSettings() {
    this->CurrentAdvertisedDLC = NULL;
}

TArray<UGameDLC*> UGameDLCSettings::GetStoreDLCs(UObject* WorldContext) {
    return TArray<UGameDLC*>();
}

TArray<UGameDLC*> UGameDLCSettings::GetAnnouncableDLCs(UObject* WorldContext) {
    return TArray<UGameDLC*>();
}


