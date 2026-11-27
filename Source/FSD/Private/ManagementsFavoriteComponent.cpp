#include "ManagementsFavoriteComponent.h"

UManagementsFavoriteComponent::UManagementsFavoriteComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ShoutMissionControlResponse = NULL;
    this->NitraDebtMessageTiers.AddDefaulted(3);
}


