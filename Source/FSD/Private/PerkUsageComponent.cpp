#include "PerkUsageComponent.h"
#include "Net/UnrealNetwork.h"

UPerkUsageComponent::UPerkUsageComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LateJoinTimeStamp = -1.00f;
}

void UPerkUsageComponent::Server_RestorePerkUse_Implementation(UPerkAsset* Perk) {
}

void UPerkUsageComponent::Server_MarkPerkUsed_Implementation(UPerkAsset* Perk) {
}

void UPerkUsageComponent::Server_CheatReset_Implementation() {
}

void UPerkUsageComponent::OnRep_PerkUsageReplicated() {
}

void UPerkUsageComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPerkUsageComponent, PerkUsageReplicated);
    DOREPLIFETIME(UPerkUsageComponent, LateJoinTimeStamp);
}


