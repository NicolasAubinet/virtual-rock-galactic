#pragma once
#include "CoreMinimal.h"
#include "BreachVentDelegateDelegate.generated.h"

class ABreachDrillVent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBreachVentDelegate, ABreachDrillVent*, vent);

