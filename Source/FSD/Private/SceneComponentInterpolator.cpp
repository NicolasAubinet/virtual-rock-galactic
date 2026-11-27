#include "SceneComponentInterpolator.h"

USceneComponentInterpolator::USceneComponentInterpolator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TargetComponent = NULL;
    this->Easing = EEasingFunc::EaseInOut;
    this->BlendExponent = 2.00f;
    this->Steps = 2;
    this->ActiveComponent = NULL;
}

void USceneComponentInterpolator::TransformTo(const FTransform& RelativeTransform, float Duration) {
}

void USceneComponentInterpolator::Stop(bool SnapToTarget) {
}

void USceneComponentInterpolator::ScaleTo(FVector RelativeScale, float Duration) {
}

void USceneComponentInterpolator::RotateTo(FRotator RelativeRotation, float Duration) {
}

void USceneComponentInterpolator::MoveTo(FVector RelativeLocation, float Duration) {
}

bool USceneComponentInterpolator::IsInterpolating() const {
    return false;
}

float USceneComponentInterpolator::GetProgress() const {
    return 0.0f;
}


