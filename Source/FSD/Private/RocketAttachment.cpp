#include "RocketAttachment.h"
#include "CarryingItemUsable.h"
#include "DroneUseComponent.h"
#include "Net/UnrealNetwork.h"
#include "SingleUsableComponent.h"

ARocketAttachment::ARocketAttachment(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAlwaysRelevant = true;
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->AttachUsable = CreateDefaultSubobject<UCarryingItemUsable>(TEXT("AttachUsable"));
    this->BuildUsable = CreateDefaultSubobject<USingleUsableComponent>(TEXT("BuildUsable"));
    this->DroneUsable = CreateDefaultSubobject<UDroneUseComponent>(TEXT("DroneUsable"));
    this->State = ERocketAttachmentState::Hidden;
}

void ARocketAttachment::SetState(ERocketAttachmentState NewState) {
}

void ARocketAttachment::SetDroneCanUse(const bool bCanUse) {
}


void ARocketAttachment::OnRep_State() {
}


ERocketAttachmentState ARocketAttachment::GetState() const {
    return ERocketAttachmentState::Hidden;
}


void ARocketAttachment::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARocketAttachment, State);
}


