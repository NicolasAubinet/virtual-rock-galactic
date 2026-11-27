#include "PerkMaintenanceItemWidget.h"

UPerkMaintenanceItemWidget::UPerkMaintenanceItemWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->PerkTooltipWidgetClass = NULL;
    this->Perk = NULL;
    this->bIsMaxed = false;
    this->MaintenanceProgress = 0.00f;
    this->InspectButton = NULL;
}

void UPerkMaintenanceItemWidget::SetViewModel(const FPerkMaintenanceWidgetViewModel& InViewModel) {
}

void UPerkMaintenanceItemWidget::SetPerk(UObject* WorldContext, UPerkAsset* InPerk) {
}

void UPerkMaintenanceItemWidget::RefreshFromSavegame(UObject* WorldContext) {
}





UWidget* UPerkMaintenanceItemWidget::GetPerkTooltip() {
    return NULL;
}


