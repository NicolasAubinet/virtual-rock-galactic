#pragma once
#include "CoreMinimal.h"
#include "EExtractionDrillState.h"
#include "ExtractionDrillStateDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FExtractionDrillStateDelegate, EExtractionDrillState, NewState);

