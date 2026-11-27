#pragma once
#include "CoreMinimal.h"
#include "ERocketAttachmentState.h"
#include "OnRocketAttachmentDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRocketAttachmentDelegate, ERocketAttachmentState, NewState);

