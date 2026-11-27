#include "MicrowaveSinusoidalChargeWidget.h"

UMicrowaveSinusoidalChargeWidget::UMicrowaveSinusoidalChargeWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->alpha = 0.00f;
    this->ElementCount = 4;
    this->Bleed = 0.35f;
    this->Exponent = 1.00f;
    this->MinOpacity = 0.00f;
    this->MaxOpacity = 1.00f;
    this->DriveBoundWidgetOpacity = true;
    this->element_0 = NULL;
    this->element_1 = NULL;
    this->element_2 = NULL;
    this->element_3 = NULL;
}

void UMicrowaveSinusoidalChargeWidget::UnbindFromMicrowaveWeapon() {
}

void UMicrowaveSinusoidalChargeWidget::SetAlpha(float InAlpha) {
}

void UMicrowaveSinusoidalChargeWidget::RefreshElementAlphas() {
}


TArray<float> UMicrowaveSinusoidalChargeWidget::GetElementAlphas() const {
    return TArray<float>();
}

float UMicrowaveSinusoidalChargeWidget::GetElementAlpha(int32 Index) const {
    return 0.0f;
}

AMicrowaveWeapon* UMicrowaveSinusoidalChargeWidget::GetBoundMicrowaveWeapon() const {
    return NULL;
}

float UMicrowaveSinusoidalChargeWidget::GetAlpha() const {
    return 0.0f;
}

float UMicrowaveSinusoidalChargeWidget::ComputeElementAlpha(float InAlpha, int32 Index, int32 InElementCount, float InBleed, float InExponent) {
    return 0.0f;
}

void UMicrowaveSinusoidalChargeWidget::BindToMicrowaveWeapon(AMicrowaveWeapon* InWeapon) {
}


