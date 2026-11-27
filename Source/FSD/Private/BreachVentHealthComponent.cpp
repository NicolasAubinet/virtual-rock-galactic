#include "BreachVentHealthComponent.h"

UBreachVentHealthComponent::UBreachVentHealthComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bShowHealthBar = true;
    this->IgnorePlayerDamage = true;
}


