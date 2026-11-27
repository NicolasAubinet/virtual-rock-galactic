#include "CableStart.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CableUsable.h"
#include "Net/UnrealNetwork.h"
#include "OutlineComponent.h"
#include "SimpleObjectInfoComponent.h"

ACableStart::ACableStart(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRootComponent"));
    this->StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    this->OutlineComponent = CreateDefaultSubobject<UOutlineComponent>(TEXT("OutlineComponent"));
    this->ObjectInfoComponent = CreateDefaultSubobject<USimpleObjectInfoComponent>(TEXT("ObjectInfo"));
    this->CableStartUsable = CreateDefaultSubobject<UCableUsable>(TEXT("CableStartUsable"));
    this->bCableConnected = false;
    this->StaticMesh->SetupAttachment(RootComponent);
}

void ACableStart::RegisterCableEnd_Implementation(ACableEnd* CableEnd) {
}


void ACableStart::OnRep_CableConnected() {
}

void ACableStart::OnCableConnected(UCableEndPoint* EndPoint, ACable* Cable) {
}

void ACableStart::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ACableStart, bCableConnected);
}


