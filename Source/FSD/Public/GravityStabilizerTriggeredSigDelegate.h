#pragma once
#include "CoreMinimal.h"
#include "GravityStabilizerTriggeredSigDelegate.generated.h"

class AGravityStabilizer;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGravityStabilizerTriggeredSig, AGravityStabilizer*, Stabilizer);

