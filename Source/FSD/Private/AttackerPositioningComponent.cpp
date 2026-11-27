#include "AttackerPositioningComponent.h"

UAttackerPositioningComponent::UAttackerPositioningComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoActivate = true;
    this->DebugPositions = false;
    this->MaxAttackers = 32;
    this->BonusAttackers = 0;
    this->FreePositions.AddDefaulted(32);
    this->FlyingFreePositions.AddDefaulted(32);
    this->CharacterPersonalSphere = 60.00f;
    this->CharacterHalfHeight = 60.00f;
    this->ScoreModifier = 1.00f;
}

void UAttackerPositioningComponent::UnregisterAttacker(AActor* Attacker, bool IsFlying) {
}

void UAttackerPositioningComponent::RegisterAttacker(AActor* Attacker, bool IsFlying) {
}

void UAttackerPositioningComponent::OnFlyingAttackerDeath(UHealthComponentBase* HealthComponent) {
}

void UAttackerPositioningComponent::OnAttackerDeath(UHealthComponentBase* HealthComponent) {
}

bool UAttackerPositioningComponent::IsAttackerRegistered(AActor* Attacker, bool IsFlying) {
    return false;
}

FVector UAttackerPositioningComponent::GetFlyingAttackerPosition(AActor* Attacker, float AttackerRadius) {
    return FVector{};
}

FVector UAttackerPositioningComponent::GetAttackerPosition(AActor* Attacker, float AttackerRadius) {
    return FVector{};
}


