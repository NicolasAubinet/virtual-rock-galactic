#include "ScrabAnimInstance.h"

UScrabAnimInstance::UScrabAnimInstance() {
    this->bIsFlying = false;
    this->bIsFlyingAndMoving = false;
    this->bIsFlyingAndNotMoving = false;
    this->ScrabDeathAnimationCategory = EScrabDeathAnimationCategory::NoAnimation;
}

void UScrabAnimInstance::SetScrabDeathAnimationCategory(EScrabDeathAnimationCategory Category) {
}


