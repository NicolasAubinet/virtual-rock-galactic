#pragma once
#include "CoreMinimal.h"
#include "CableConnectionDelegateDelegate.generated.h"

class ACable;
class UCableEndPoint;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCableConnectionDelegate, UCableEndPoint*, EndPoint, ACable*, Cable);

