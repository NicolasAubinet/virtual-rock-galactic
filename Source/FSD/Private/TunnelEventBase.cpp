#include "TunnelEventBase.h"
#include "Components/BillboardComponent.h"
#include "Components/SceneComponent.h"

ATunnelEventBase::ATunnelEventBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->EntranceDebrisRadiusScale = 2.00f;
    this->AutoTriggerDelay = 30.00f;
    this->Root = (USceneComponent*)RootComponent;
    this->Adders = CreateDefaultSubobject<USceneComponent>(TEXT("Adders"));
    this->Removers = CreateDefaultSubobject<USceneComponent>(TEXT("Removers"));
    this->TunnelEntranceCarvers = CreateDefaultSubobject<USceneComponent>(TEXT("TunnelEntranceCarvers"));
    this->DebrisParent = CreateDefaultSubobject<USceneComponent>(TEXT("DebrisParent"));
    this->EntranceIndicator = CreateDefaultSubobject<UBillboardComponent>(TEXT("EntranceIndicator"));
    this->Adders->SetupAttachment(RootComponent);
    this->DebrisParent->SetupAttachment(RootComponent);
    this->EntranceIndicator->SetupAttachment(RootComponent);
    this->Removers->SetupAttachment(RootComponent);
    this->TunnelEntranceCarvers->SetupAttachment(RootComponent);
}


void ATunnelEventBase::CarveEntranceWithBiomeDirt() {
}

void ATunnelEventBase::AddSpawnedGem(AGem* Gem) {
}


