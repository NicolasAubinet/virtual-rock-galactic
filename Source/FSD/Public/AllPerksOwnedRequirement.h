#pragma once
#include "CoreMinimal.h"
#include "CampaignRequirement.h"
#include "AllPerksOwnedRequirement.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class FSD_API UAllPerksOwnedRequirement : public UCampaignRequirement {
    GENERATED_BODY()
public:
    UAllPerksOwnedRequirement();

};

