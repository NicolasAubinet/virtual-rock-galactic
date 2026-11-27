#pragma once
#include "CoreMinimal.h"
#include "ECoreCorruptionCrystalState.h"
#include "CoreCorruptionCrystalDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCoreCorruptionCrystalDelegate, ECoreCorruptionCrystalState, State);

