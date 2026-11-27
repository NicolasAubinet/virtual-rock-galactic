#pragma once
#include "CoreMinimal.h"
#include "FireModeChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFireModeChangedDelegate, bool, bIsAltFireActive);

