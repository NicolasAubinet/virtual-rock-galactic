#include "Cable.h"
#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

ACable::ACable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
    this->DesignatedCableEnd = NULL;
    this->CableSplineMesh = CreateDefaultSubobject<USplineMeshComponent>(TEXT("CableSplineMesh"));
    this->CableSplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("CableSplineComponent"));
    this->CableEndPostMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CableEndPostMesh"));
    this->PreviewEndPostLocation = CreateDefaultSubobject<USceneComponent>(TEXT("PreviewEndPostLocation"));
    this->MaxLength = 1000.00f;
    this->CableEndPostMesh->SetupAttachment(RootComponent);
    this->CableSplineComponent->SetupAttachment(RootComponent);
    this->CableSplineMesh->SetupAttachment(RootComponent);
    this->PreviewEndPostLocation->SetupAttachment(RootComponent);
}

bool ACable::UpdatePlacement(const FTransform& InTransform, ACableEnd* InCableEnd, AItem* PlaceableItem) {
    return false;
}





bool ACable::ReceiveCanPlaceAt_Implementation(const FTransform& InCandidateTransform, ACableEnd* InCableEnd) {
    return false;
}

void ACable::OnRep_CableEndTransform() {
}

ETrackBuildPlacementState ACable::GetPlacementState() const {
    return ETrackBuildPlacementState::NotBeingPlaced;
}

bool ACable::GetIsCableEndTransformValid() const {
    return false;
}

FTransform ACable::GetCableEndTransform() const {
    return FTransform{};
}

bool ACable::CanPlaceAt(const FTransform& InCandidateTransform, ACableEnd* InCableEnd, AItem* PlaceableItem) {
    return false;
}

void ACable::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ACable, BuiltByCharacter);
    DOREPLIFETIME(ACable, BuiltFromUsable);
    DOREPLIFETIME(ACable, ServerCableEndTransform);
}


