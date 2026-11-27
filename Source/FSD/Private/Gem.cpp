#include "Gem.h"
#include "CarriableInstantUsable.h"

AGem::AGem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Usable = CreateDefaultSubobject<UCarriableInstantUsable>(TEXT("Usable"));
    this->ResourceType = NULL;
    this->ResourceAmount = 1.00f;
    this->hasBeenReleased = false;
    this->canPickUpBeforeReleased = false;
}

void AGem::SetHasBeenReleased(bool NewHasBeenReleased) {
}

void AGem::SetCanPickUpBeforeReleased(bool NewCanPickUpBeforeReleased) {
}

void AGem::RollResourceAmount() {
}

bool AGem::GetHasBeenReleased() const {
    return false;
}

bool AGem::GetCanPickUpBeforeReleased() const {
    return false;
}


