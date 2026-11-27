#include "PowerBootsChargeWidget.h"

UPowerBootsChargeWidget::UPowerBootsChargeWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->DrainSpeed = 10.00f;
    this->FadeInSpeed = 20.00f;
    this->FadeOutSpeed = 6.00f;
    this->IdleOpacity = 0.00f;
    this->MaxShakeOffset = 6.00f;
    this->ShakeFrequency = 25.00f;
}



void UPowerBootsChargeWidget::SetShakeProgress(float Progress) {
}




