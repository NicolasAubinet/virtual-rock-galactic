#include "PerkMaintenanceTabWidget.h"

UPerkMaintenanceTabWidget::UPerkMaintenanceTabWidget() {
    this->StarterBonusPopup = NULL;
    this->PerkItemWidgetClass = NULL;
    this->PerkGridColumns = 6;
    this->PerkGridPanel = NULL;
    this->RewardContainer = NULL;
}

bool UPerkMaintenanceTabWidget::HasNewNotifications(UObject* WorldContext) const {
    return false;
}

void UPerkMaintenanceTabWidget::HandleStarterBonusPopupClicked(bool bYes) {
}

void UPerkMaintenanceTabWidget::HandlePerkMaintenanceChanged() {
}

void UPerkMaintenanceTabWidget::CreatePerkMaintenanceWidgets(UObject* WorldContext) {
}

bool UPerkMaintenanceTabWidget::ClaimReward(UObject* WorldContext) {
    return false;
}


