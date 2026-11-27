#include "ProceduralConformComponent.h"

UProceduralConformComponent::UProceduralConformComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoActivate = true;
    this->LegChainSegments = 2;
    this->bConformEnabled = true;
    this->bSweepFromRefPose = true;
    this->TraceObjectTypes.AddDefaulted(2);
    this->bTraceComplex = false;
    this->bEnableInwardSweeps = true;
    this->bRejectOccludedTargets = true;
    this->OcclusionSkin = 6.00f;
    this->InwardSweepBiases.AddDefaulted(4);
    this->InwardSweepLength = 90.00f;
    this->InwardSweepStartBackoff = 20.00f;
    this->bResolveInitialPenetration = true;
    this->bFadeWithDistance = false;
    this->SwingFadeStart = 12.00f;
    this->SwingFadeEnd = 45.00f;
    this->FootInterpSpeed = 14.00f;
    this->FootRotationInterpSpeed = 10.00f;
    this->MaxFootTiltDegrees = 45.00f;
    this->MaxFootCorrection = 0.00f;
    this->bFitBodyToContacts = true;
    this->MinContactsForBodyTilt = 2;
    this->MaxBodyTiltDegrees = 35.00f;
    this->BodyInterpSpeed = 6.00f;
    this->BodyTiltScale = 1.00f;
    this->bProbeBodyClearance = true;
    this->BodyProbeRadius = 20.00f;
    this->BodyClearance = 40.00f;
    this->BodyProbeDistance = 300.00f;
    this->BodyMaxRaise = 300.00f;
    this->BodyMaxLower = 300.00f;
    this->bDrawDebug = false;
    this->ResolvedMesh = NULL;
}

void UProceduralConformComponent::SetTargetMesh(USkeletalMeshComponent* InMesh) {
}

bool UProceduralConformComponent::IsLegValid(int32 LegIndex) const {
    return false;
}

int32 UProceduralConformComponent::GetNumLegs() const {
    return 0;
}

FVector UProceduralConformComponent::GetLegTargetComponentSpace(int32 LegIndex) const {
    return FVector{};
}

bool UProceduralConformComponent::GetLegResult(int32 LegIndex, FConformLegResult& OutResult) const {
    return false;
}

FVector UProceduralConformComponent::GetLegEffectorOffset(int32 LegIndex) const {
    return FVector{};
}

FVector UProceduralConformComponent::GetLegAnimatedLocationComponentSpace(int32 LegIndex) const {
    return FVector{};
}

FVector UProceduralConformComponent::GetBodyLocationOffset() const {
    return FVector{};
}

FRotator UProceduralConformComponent::GetBodyDeltaRotation() const {
    return FRotator{};
}

void UProceduralConformComponent::DrawDebugPreview() {
}


