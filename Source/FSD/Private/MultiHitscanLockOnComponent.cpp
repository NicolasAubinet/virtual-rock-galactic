#include "MultiHitscanLockOnComponent.h"

UMultiHitscanLockOnComponent::UMultiHitscanLockOnComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MaxLockedBeams = 5;
    this->LockOnDelay = 0.10f;
    this->FiringResetDelay = 0.25f;
    this->LockOnAreaScale = 1.00f;
    this->PulseSpeed = 0.32f;
    this->OuterRotationSpeed = 45.00f;
    this->OuterMinRadius = 8.00f;
    this->OuterMaxRadius = 12.00f;
    this->InnerRotationSpeed = -90.00f;
    this->InnerMinRadius = 3.00f;
    this->InnerMaxRadius = 6.00f;
}


