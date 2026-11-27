#include "PerkMaintenanceRewardWidget.h"

UPerkMaintenanceRewardWidget::UPerkMaintenanceRewardWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->SkinTooltipWidgetClass = NULL;
    this->PreviewButton = NULL;
    this->UnlockButton = NULL;
    this->TrackIndex = -1;
}

void UPerkMaintenanceRewardWidget::SetTrack(UObject* WorldContext, int32 InTrackIndex) {
}




void UPerkMaintenanceRewardWidget::HandleUnlockButtonClicked() {
}

UWidget* UPerkMaintenanceRewardWidget::GetSkinTooltip() {
    return NULL;
}


