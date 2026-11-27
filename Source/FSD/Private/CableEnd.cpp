#include "CableEnd.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CableEndPoint.h"

ACableEnd::ACableEnd(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->EndPoint = CreateDefaultSubobject<UCableEndPoint>(TEXT("EndPoint"));
    this->StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    this->EndPoint->SetupAttachment(RootComponent);
    this->StaticMesh->SetupAttachment(RootComponent);
}





void ACableEnd::OnConnected(UCableEndPoint* InEndPoint, ACable* InCable) {
}

UCableEndPoint* ACableEnd::GetEndPoint() const {
    return NULL;
}


