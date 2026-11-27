#include "MissionDrinkItem.h"
#include "CapacityHoldingItemAggregator.h"
#include "Net/UnrealNetwork.h"

AMissionDrinkItem::AMissionDrinkItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Capacity = CreateDefaultSubobject<UCapacityHoldingItemAggregator>(TEXT("Capacity"));
    this->FPDrinkMontage = NULL;
    this->TPDrinkMontage = NULL;
    this->Item_EquipAnimation = NULL;
    this->Item_DrinkAnimation = NULL;
    this->SaluteShoutOverride = NULL;
    this->ShoutOnEquipEmpty = NULL;
    this->CooldownAfterDrink = 1.00f;
    this->CanDrinkBeforeEquipAnimFinish = false;
    this->CooldownAfterEquip = 0.25f;
    this->FromStartDrinkingTillBuffActiveTime = 0.00f;
    this->SupplyStatusWeight = 1.00f;
    this->DrinkBuff = NULL;
    this->DrinkBuffDuration = -1.00f;
    this->DrinkBuffInstance = NULL;
    this->IntoxicationDuration = -1.00f;
    this->IntoxicationRecovery = 1.00f;
    this->CooldownLeft = 0.00f;
    this->AnimationPlaybackRate = 1.00f;
}

void AMissionDrinkItem::ServerPlayDrinkAnimation_Implementation() {
}

void AMissionDrinkItem::ServerOnIntoxicationExpired_Implementation() {
}

void AMissionDrinkItem::Server_Drink_Implementation() {
}


void AMissionDrinkItem::OnMatchEnded() {
}

void AMissionDrinkItem::MulticastPlayDrinkAnimation_Implementation() {
}

void AMissionDrinkItem::MulticastOnIntoxicationExpired_Implementation() {
}


void AMissionDrinkItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AMissionDrinkItem, CooldownLeft);
}


