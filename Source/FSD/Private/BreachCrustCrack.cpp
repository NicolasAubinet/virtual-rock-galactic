#include "BreachCrustCrack.h"
#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"
#include "Net/UnrealNetwork.h"

ABreachCrustCrack::ABreachCrustCrack(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->CrackPath = CreateDefaultSubobject<USplineComponent>(TEXT("CrackPath"));
    this->CarverComponentTag = TEXT("Crack");
    this->CrackDuration = 8.00f;
    this->CrackCurve = NULL;
    this->PathPointCount = 8;
    this->PathNoiseHorizontal = 800.00f;
    this->PathNoiseVertical = 250.00f;
    this->SnapPathToGround = true;
    this->PathStepSize = 300.00f;
    this->MaxStepClimb = 200.00f;
    this->MaxStepDrop = 1200.00f;
    this->GroundTraceDown = 4000.00f;
    this->GroundOffset = -50.00f;
    this->ArrivalPenetration = 400.00f;
    this->KeepStartHeight = true;
    this->AlignToPath = true;
    this->DriveCarving = true;
    this->CarveSpacing = 100.00f;
    this->MaxCarvesPerFrame = 32;
    this->CarveOnArrival = true;
    this->DestroyDelay = 5.00f;
    this->DebugShowPath = false;
    this->DebugPathThickness = 6.00f;
    this->DebugPathSegmentsPerPoint = 6;
    this->PathSeed = 0;
    this->CrackStartTime = -1.00f;
    this->CrackPath->SetupAttachment(RootComponent);
}

void ABreachCrustCrack::StartCrackTowardsActor(AActor* Destination, int32 Seed) {
}

void ABreachCrustCrack::StartCrack(const FVector& StartLocation, const FVector& EndLocation, int32 Seed) {
}

void ABreachCrustCrack::SetDebugShowPath(bool Show) {
}

void ABreachCrustCrack::OnRep_CrackStartTime() {
}




bool ABreachCrustCrack::IsCracking() const {
    return false;
}

USplineComponent* ABreachCrustCrack::GetCrackPath() const {
    return NULL;
}

float ABreachCrustCrack::GetCrackAlpha() const {
    return 0.0f;
}

void ABreachCrustCrack::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ABreachCrustCrack, PathStart);
    DOREPLIFETIME(ABreachCrustCrack, PathEnd);
    DOREPLIFETIME(ABreachCrustCrack, PathSeed);
    DOREPLIFETIME(ABreachCrustCrack, CrackStartTime);
}


