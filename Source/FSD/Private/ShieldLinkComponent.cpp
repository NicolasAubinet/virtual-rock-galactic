#include "ShieldLinkComponent.h"

UShieldLinkComponent::UShieldLinkComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LongRangeAimRadius = 100.00f;
    this->LongRangeAimRadiusStat = NULL;
    this->LongRangeTarget = NULL;
    this->LongRangeUsable = NULL;
    this->BoostedStatusEffect = NULL;
    this->BoostedStatusEffectInstance = NULL;
    this->LinkDistance = 300.00f;
    this->LinkDistanceStat = NULL;
    this->LinkStatusEffect = NULL;
}

void UShieldLinkComponent::TimerFunction() {
}


