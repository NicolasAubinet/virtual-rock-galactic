#pragma once
#include "CoreMinimal.h"
#include "OnPerkMaintenanceRewardGrantedDelegate.generated.h"

class UItemID;
class UItemSkin;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPerkMaintenanceRewardGranted, UItemSkin*, Skin, UItemID*, TraversalTool);

