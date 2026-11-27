#include "ExtractionDrillElevator.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

AExtractionDrillElevator::AExtractionDrillElevator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    this->TravelDuration = 4.00f;
    this->BottomDwellDuration = 1.00f;
    this->TopDwellDuration = 1.00f;
    this->PhaseOffset = 0.00f;
    this->bRunning = false;
    this->StopTime = 0.00f;
    this->PlatformMesh->SetupAttachment(RootComponent);
}

void AExtractionDrillElevator::SetShaftEnds(const FVector& Bottom, const FVector& Top) {
}

void AExtractionDrillElevator::SetRunning(bool running) {
}

void AExtractionDrillElevator::OnShaftDeployed_Implementation(const FVector& Bottom, const FVector& Top) {
}

void AExtractionDrillElevator::OnRep_ShaftEnds() {
}

void AExtractionDrillElevator::OnRep_Running() {
}

void AExtractionDrillElevator::OnElevatorAlpha_Implementation(float alpha) {
}

bool AExtractionDrillElevator::IsRunning() const {
    return false;
}

bool AExtractionDrillElevator::IsDwelling() const {
    return false;
}

bool AExtractionDrillElevator::HasShaftEnds() const {
    return false;
}

FVector AExtractionDrillElevator::GetShaftTop() const {
    return FVector{};
}

FVector AExtractionDrillElevator::GetShaftBottom() const {
    return FVector{};
}

UStaticMeshComponent* AExtractionDrillElevator::GetPlatformMesh() const {
    return NULL;
}

FVector AExtractionDrillElevator::GetPlatformLocation() const {
    return FVector{};
}

float AExtractionDrillElevator::GetElevatorAlpha() const {
    return 0.0f;
}

void AExtractionDrillElevator::DeployInShaft() {
}

void AExtractionDrillElevator::CaptureShaftTop() {
}

void AExtractionDrillElevator::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AExtractionDrillElevator, ShaftBottom);
    DOREPLIFETIME(AExtractionDrillElevator, ShaftTop);
    DOREPLIFETIME(AExtractionDrillElevator, PhaseOffset);
    DOREPLIFETIME(AExtractionDrillElevator, bRunning);
    DOREPLIFETIME(AExtractionDrillElevator, StopTime);
}


