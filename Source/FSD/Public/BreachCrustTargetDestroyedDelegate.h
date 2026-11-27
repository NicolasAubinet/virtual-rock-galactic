#pragma once
#include "CoreMinimal.h"
#include "BreachCrustTargetDestroyedDelegate.generated.h"

class ABreachCrustTarget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBreachCrustTargetDestroyed, ABreachCrustTarget*, Target);

