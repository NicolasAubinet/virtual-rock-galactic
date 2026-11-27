#pragma once
#include "CoreMinimal.h"
#include "ShieldGainedFromKillDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FShieldGainedFromKill, float, amount);

