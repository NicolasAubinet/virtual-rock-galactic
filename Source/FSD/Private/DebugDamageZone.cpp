#include "DebugDamageZone.h"
#include "Components/BoxComponent.h"

ADebugDamageZone::ADebugDamageZone(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Zone"));
    this->Zone = (UBoxComponent*)RootComponent;
    this->damageAmount = 10.00f;
    this->DamageInterval = 0.50f;
    this->DamageClass = NULL;
    this->VisibleInGame = true;
}


