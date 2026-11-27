#include "AmberExcavation.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

AAmberExcavation::AAmberExcavation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->NetDormancy = DORM_DormantAll;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->Root = (USceneComponent*)RootComponent;
    this->StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    this->StaticMesh->SetupAttachment(RootComponent);
}

void AAmberExcavation::SetRocketAttachments(TArray<ARocketAttachment*> InRocketAttachments) {
}



void AAmberExcavation::OnRocketAttachmentStateChanged(ERocketAttachmentState NewState) {
}

void AAmberExcavation::OnExcavationPhaseFinished() {
}



TEnumAsByte<EAmberDepositPhase> AAmberExcavation::GetCurrentPhase() const {
    return Excavation;
}


