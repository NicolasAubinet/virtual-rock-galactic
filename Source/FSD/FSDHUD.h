#pragma once

#include "CoreMinimal.h"
#include "FSD_struct.h"
#include "GameFramework/HUD.h"
#include "FSDHUD.generated.h"

class APlayerController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFSDHUDOnHUDVisibilityChanged, bool, InHudVisible);

UCLASS()
class FSD_API AFSDHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable) FFSDHUDOnHUDVisibilityChanged OnHUDVisibilityChanged;

	UFUNCTION(BlueprintCallable) void SetHUDVisible(bool IsVisible, EHUDVisibilityReason reason) {}
	UFUNCTION(BlueprintCallable) static AFSDHUD* GetFSDHUD(APlayerController* InPlayerController) { return nullptr; }
};
