#pragma once
#include "CoreMinimal.h"
#include "CableDelegateDelegate.generated.h"

class ACable;
class UCableUsable;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCableDelegate, UCableUsable*, InUsable, ACable*, InCable);

