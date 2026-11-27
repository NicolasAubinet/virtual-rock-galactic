#include "CableBuilderItem.h"
#include "CrosshairAggregator.h"
#include "ItemPlacerAggregator.h"
#include "Net/UnrealNetwork.h"

ACableBuilderItem::ACableBuilderItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CrosshairAggregator = CreateDefaultSubobject<UCrosshairAggregator>(TEXT("CrosshairAggregator"));
    this->CablePlacer = CreateDefaultSubobject<UItemPlacerAggregator>(TEXT("CablePlacer"));
    this->ObstructionType = EPlaceableObstructionType::Valid;
    this->DefaultCableType = NULL;
    this->Cable = NULL;
    this->bIsPlacingCable = false;
}

void ACableBuilderItem::UpdatePlacement(const FTransform& InTransform, ACableEnd* InCableEnd, bool bPlacementValid, bool InUpdateServer) {
}

void ACableBuilderItem::ServerUpdatePlacement_Implementation(const FTransform& InTransform, const bool bPlacementValid, ACableEnd* InCableEnd) {
}

void ACableBuilderItem::ServerFinishPlacement_Implementation(const FTransform& FinalLocation, ACableEnd* CableEnd) {
}

void ACableBuilderItem::ServerCancelPlacement_Implementation() {
}

void ACableBuilderItem::ServerBeginPlaceCable_Implementation(UCableUsable* InUsable) {
}



void ACableBuilderItem::OnRep_Cable() {
}

void ACableBuilderItem::FinishPlacement(const FTransform& FinalLocation, ACableEnd* CableEnd) {
}

void ACableBuilderItem::CancelPlacement() {
}

void ACableBuilderItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ACableBuilderItem, Cable);
    DOREPLIFETIME(ACableBuilderItem, bIsPlacingCable);
}


