#pragma once
#include "CoreMinimal.h"
#include "BreachChargeDetonatedDelegate.generated.h"

class ABreachCharge;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBreachChargeDetonated, ABreachCharge*, charge);

