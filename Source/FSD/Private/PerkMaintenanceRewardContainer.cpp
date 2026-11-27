#include "PerkMaintenanceRewardContainer.h"

UPerkMaintenanceRewardContainer::UPerkMaintenanceRewardContainer() : UUserWidget(FObjectInitializer::Get()) {
    this->RewardWidgetClass = NULL;
    this->RewardPanel = NULL;
}

void UPerkMaintenanceRewardContainer::RefreshRewardWidgets(UObject* WorldContext) {
}


