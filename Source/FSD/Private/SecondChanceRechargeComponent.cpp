#include "SecondChanceRechargeComponent.h"
#include "Net/UnrealNetwork.h"

USecondChanceRechargeComponent::USecondChanceRechargeComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ShoutOnUseRestored = NULL;
    this->HealthThresholdPercent = 100.00f;
    this->RechargeStartTime = -1.00f;
    this->RechargeDuration = 0.00f;
}

void USecondChanceRechargeComponent::OnHealthChanged(float Health) {
}

float USecondChanceRechargeComponent::GetRechargeProgress() const {
    return 0.0f;
}

void USecondChanceRechargeComponent::CheckToRestore() {
}

void USecondChanceRechargeComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(USecondChanceRechargeComponent, RechargeStartTime);
    DOREPLIFETIME(USecondChanceRechargeComponent, RechargeDuration);
}


