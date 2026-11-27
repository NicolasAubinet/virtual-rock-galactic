#include "MultiHitscanUniformComponent.h"

UMultiHitscanUniformComponent::UMultiHitscanUniformComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TraceDensity = 10.00f;
    this->ConeHalfAngle = 10.00f;
    this->ConeLength = 1000.00f;
    this->DamageMultiplierPerHit = 0.50f;
    this->bShowImpactOnHit = false;
    this->GeneralImpactAudioVolume = 1.00f;
    this->bPlayImpactSound = true;
}

void UMultiHitscanUniformComponent::Server_RegisterHit_Implementation(const FMultiHitScanHits& hitResults) {
}

float UMultiHitscanUniformComponent::GetRange() const {
    return 0.0f;
}

float UMultiHitscanUniformComponent::GetHalfAngle() const {
    return 0.0f;
}

void UMultiHitscanUniformComponent::All_ShowHit_Implementation(const FMultiHitScanHits& hitResults) {
}


