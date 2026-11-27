#pragma once
#include "CoreMinimal.h"
#include "ESprintMode.h"
#include "SprintModeChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSprintModeChanged, ESprintMode, NewValue);

