#pragma once
#include "CoreMinimal.h"
#include "ProjectileSpreadChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FProjectileSpreadChangedDelegate, float, HorizontalSpread, float, VerticalSpread);

