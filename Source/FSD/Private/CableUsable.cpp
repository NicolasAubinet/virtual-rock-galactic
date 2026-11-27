#include "CableUsable.h"
#include "Net/UnrealNetwork.h"

UCableUsable::UCableUsable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BuilderItemType = NULL;
    this->CableStartComponent = NULL;
    this->Cable = NULL;
    this->DesignatedCableEnd = NULL;
}

void UCableUsable::OnRep_CableSegment() {
}

FTransform UCableUsable::GetStartTransform() const {
    return FTransform{};
}

void UCableUsable::FinishUse(APlayerCharacter* User, ACable* InCable) {
}

void UCableUsable::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UCableUsable, Cable);
    DOREPLIFETIME(UCableUsable, InUseBy);
    DOREPLIFETIME(UCableUsable, DesignatedCableEnd);
}


