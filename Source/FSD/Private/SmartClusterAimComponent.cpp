#include "SmartClusterAimComponent.h"

USmartClusterAimComponent::USmartClusterAimComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SearchRadius = 1500.00f;
    this->PlayerSafetyMargin = 50.00f;
    this->SharedTargetSpreadAngle = 2.00f;
    this->AltitudeWeight = 0.50f;
}

void USmartClusterAimComponent::AimClusters(const TArray<AProjectile*>& Clusters) {
}


