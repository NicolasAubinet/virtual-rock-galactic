#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LoadoutCopy.h"
#include "LoadoutFunctionLibrary.generated.h"

class APlayerCharacter;
class UObject;
class UPlayerCharacterID;

UCLASS(Blueprintable)
class FSD_API ULoadoutFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    ULoadoutFunctionLibrary();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetCurrLoadout(UObject* WorldContextObject, UPlayerCharacterID* playerID, FLoadoutCopy newLoadout);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RandomizeWeaponLoadout(UObject* WorldContextObject, UPlayerCharacterID* playerID, int32 loadoutIndex);
    
    UFUNCTION(BlueprintCallable)
    static void RandomizeAllRandomWeaponLoadout(APlayerCharacter* Player);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static FLoadoutCopy GetCurrentLoadout(UObject* WorldContextObject, UPlayerCharacterID* playerID);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void CopyPasteWeaponLoadout(UObject* WorldContextObject, UPlayerCharacterID* playerID, int32 fromIndex, int32 toIndex);
    
};

