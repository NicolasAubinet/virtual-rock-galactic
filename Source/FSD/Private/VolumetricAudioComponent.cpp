#include "VolumetricAudioComponent.h"

UVolumetricAudioComponent::UVolumetricAudioComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->VolumetricCollider = NULL;
    this->SoundCue = NULL;
    this->bTrackListener = true;
    this->InsideSoundMix = NULL;
    this->bSnapToListenerWhenInside = true;
    this->FarDistance = 3000.00f;
    this->FarUpdateInterval = 0.50f;
    this->UpdateInterval = 0.00f;
    this->bDrawDebug = false;
}

bool UVolumetricAudioComponent::UpdateVolumetricLocation() {
    return false;
}

void UVolumetricAudioComponent::SetVolumetricCollider(UPrimitiveComponent* aCollider) {
}

void UVolumetricAudioComponent::SetUpdateInterval(float aInterval) {
}

void UVolumetricAudioComponent::SetTrackingEnabled(bool aEnabled) {
}

void UVolumetricAudioComponent::SetSoundCue(USoundCue* aSoundCue) {
}

void UVolumetricAudioComponent::SetSnapToListenerWhenInside(bool aSnap) {
}

void UVolumetricAudioComponent::SetInsideSoundMix(USoundMix* aSoundMix) {
}

void UVolumetricAudioComponent::SetFarUpdateInterval(float aInterval) {
}

void UVolumetricAudioComponent::SetFarDistance(float aDistance) {
}

void UVolumetricAudioComponent::SetDrawDebug(bool aDrawDebug) {
}

void UVolumetricAudioComponent::SetColliderBoneName(FName aBoneName) {
}

void UVolumetricAudioComponent::PlayVolumetric(USoundCue* aSoundCue, UPrimitiveComponent* aCollider) {
}

bool UVolumetricAudioComponent::IsTrackingEnabled() const {
    return false;
}

bool UVolumetricAudioComponent::IsListenerInside() const {
    return false;
}

bool UVolumetricAudioComponent::IsListenerFarAway() const {
    return false;
}

bool UVolumetricAudioComponent::IsInsideSoundMixPushed() const {
    return false;
}

UPrimitiveComponent* UVolumetricAudioComponent::GetVolumetricCollider() const {
    return NULL;
}

USoundCue* UVolumetricAudioComponent::GetSoundCue() const {
    return NULL;
}

USoundMix* UVolumetricAudioComponent::GetInsideSoundMix() const {
    return NULL;
}

float UVolumetricAudioComponent::GetDistanceToCollider() const {
    return 0.0f;
}


