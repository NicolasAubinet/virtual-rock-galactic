#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EItemCategory.h"
#include "OverclockFunctionLibrary.generated.h"

class UOverclockUpgrade;

UCLASS(Blueprintable)
class FSD_API UOverclockFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UOverclockFunctionLibrary();

    UFUNCTION(BlueprintCallable)
    static TArray<UOverclockUpgrade*> GetSortedOverclocksByWeaponOrder(const TArray<UOverclockUpgrade*>& Overclocks, const TArray<EItemCategory>& CategoryOrder);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UOverclockUpgrade*> GetSortedOverclocks(const TArray<UOverclockUpgrade*>& Overclocks);
    
};

