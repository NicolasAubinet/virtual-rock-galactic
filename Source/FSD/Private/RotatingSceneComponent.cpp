#include "RotatingSceneComponent.h"
#include "Net/UnrealNetwork.h"

URotatingSceneComponent::URotatingSceneComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BobbingSpeed = 0.00f;
    this->BobbingSize = 0.00f;
    this->PhaseStartTime = 0.00f;
    this->Sweep = false;
    this->ForceParentUp = false;
    this->TeleportMode = ETeleportType::None;
}

void URotatingSceneComponent::Stop() {
}

void URotatingSceneComponent::Start() {
}

void URotatingSceneComponent::OnRep_PhaseStartTime() {
}

void URotatingSceneComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(URotatingSceneComponent, PhaseStartTime);
}


