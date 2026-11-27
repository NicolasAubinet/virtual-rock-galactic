#include "InkBugSac.h"
#include "Components/BoxComponent.h"
#include "InstantUsable.h"
#include "Net/UnrealNetwork.h"
#include "RotatingSceneComponent.h"

AInkBugSac::AInkBugSac(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    this->CollisionBox = (UBoxComponent*)RootComponent;
    this->CollectUsable = CreateDefaultSubobject<UInstantUsable>(TEXT("CollectUsable"));
    this->HologramAnchor = CreateDefaultSubobject<URotatingSceneComponent>(TEXT("HologramAnchor"));
    this->AquisitionSource = NULL;
    this->RewardGrantDelay = 1.00f;
    this->LifespanAfterGrant = 2.00f;
    this->CrushDelay = 0.50f;
    this->CrushStatusEffect = NULL;
    this->rewarder = NULL;
    this->bCollected = false;
    this->Claimer = NULL;
    this->HologramAnchor->SetupAttachment(RootComponent);
}


void AInkBugSac::OnRep_Collected() {
}


void AInkBugSac::HandleUsedBy(APlayerCharacter* User, EInputKeys Key) {
}

void AInkBugSac::GrantRewards() {
}

void AInkBugSac::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AInkBugSac, bCollected);
}


