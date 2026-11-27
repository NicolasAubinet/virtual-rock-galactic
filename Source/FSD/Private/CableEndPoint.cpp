#include "CableEndPoint.h"
#include "Net/UnrealNetwork.h"

UCableEndPoint::UCableEndPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ConnectType = NULL;
    this->MaxConnectRadius = 150.00f;
    this->ConnectDistance = 0.00f;
}

void UCableEndPoint::OnRep_ConnectedCable() {
}

FTransform UCableEndPoint::GetConnectTransform_Implementation(const FTransform& FromWorldTransform) {
    return FTransform{};
}

bool UCableEndPoint::Disconnect(ACable* Cable) {
    return false;
}

bool UCableEndPoint::Connect(ACable* Cable) {
    return false;
}

bool UCableEndPoint::CanConnectWith_Implementation(ACable* Cable, const FTransform& FromWorldTransform) {
    return false;
}

void UCableEndPoint::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UCableEndPoint, ConnectedCable);
}


