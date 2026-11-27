#pragma once
#include "CoreMinimal.h"
#include "ExtractionDrillSubstructureDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FExtractionDrillSubstructureDelegate, int32, groupIndex);

