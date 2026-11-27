#include "MultiHitscanComponent.h"

UMultiHitscanComponent::UMultiHitscanComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bPlayImpactSound = true;
    this->BulletsPerShot = 0;
    this->UseEvenSpread = false;
    this->GeneralImpactAudioVolume = 1.00f;
    this->CountMultiHits = false;
}

void UMultiHitscanComponent::Server_RegisterHit_Implementation(const FMultiHitScanHits& hitResults) {
}

void UMultiHitscanComponent::All_ShowHit_Implementation(const FMultiHitScanHits& hitResults) {
}


