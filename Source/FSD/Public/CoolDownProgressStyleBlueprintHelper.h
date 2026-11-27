#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoolDownProgressStyle.h"
#include "CoolDownProgressStyleBlueprintHelper.generated.h"

class APlayerCharacter;
class UObject;

UCLASS(Blueprintable)
class UCoolDownProgressStyleBlueprintHelper : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UCoolDownProgressStyleBlueprintHelper();

    UFUNCTION(BlueprintCallable)
    static void SetProgress(const FCoolDownProgressStyle& PickKillsWidgetCooldown, float Progress, UObject* ProgressOwner, APlayerCharacter* Character);
    
};

