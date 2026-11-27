#include "WalkAndFlyEnemyComponent.h"
#include "Net/UnrealNetwork.h"

UWalkAndFlyEnemyComponent::UWalkAndFlyEnemyComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CurrentMove = NULL;
    this->SpawnFlyChance = 0.00f;
    this->IsFlying = false;
    this->WalkMinTime = 0.00f;
    this->WalkTime = 0.00f;
    this->WalkTimeRandomOffset = 0.00f;
    this->WalkUseTimer = true;
    this->FlyMinTime = 0.00f;
    this->FlyTime = 0.00f;
    this->FlyTimeRandomOffset = 0.00f;
    this->FlyUseTimer = true;
}

void UWalkAndFlyEnemyComponent::SetShouldWalk(bool bShouldWalk, bool bIgnoreMinStateTime) {
}

void UWalkAndFlyEnemyComponent::SetIsFlying(bool bIsFlying) {
}

void UWalkAndFlyEnemyComponent::SetAllowedToChangeState(const bool bIsAllowed) {
}

void UWalkAndFlyEnemyComponent::OnRep_StateChange(const bool bOldIsFlying) {
}

bool UWalkAndFlyEnemyComponent::GetIsWalking() const {
    return false;
}

bool UWalkAndFlyEnemyComponent::GetIsFlying() const {
    return false;
}

void UWalkAndFlyEnemyComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UWalkAndFlyEnemyComponent, IsFlying);
}


