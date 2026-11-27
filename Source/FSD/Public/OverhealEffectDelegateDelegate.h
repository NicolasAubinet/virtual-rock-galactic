#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OverhealEffectDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOverhealEffectDelegate, FVector, Location, AActor*, Actor);

