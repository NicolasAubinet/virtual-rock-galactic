#pragma once
#include "CoreMinimal.h"
#include "ERocketAttachmentState.generated.h"

UENUM(BlueprintType)
enum class ERocketAttachmentState : uint8 {
    Hidden,
    ReadyToAttach,
    ReadyToBuild,
    Built,
    Launching,
    Finished,
};

