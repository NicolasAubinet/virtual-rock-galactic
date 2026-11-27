#pragma once
#include "CoreMinimal.h"
#include "FindSessionsCallbackProxy.h"
#include "indSessionsResultDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FindSessionsResult, bool, success, const TArray<FBlueprintSessionResult>&, Results);

