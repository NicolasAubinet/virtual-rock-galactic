#include "LoadoutFunctionLibrary.h"

ULoadoutFunctionLibrary::ULoadoutFunctionLibrary() {
}

void ULoadoutFunctionLibrary::SetCurrLoadout(UObject* WorldContextObject, UPlayerCharacterID* playerID, FLoadoutCopy newLoadout) {
}

void ULoadoutFunctionLibrary::RandomizeWeaponLoadout(UObject* WorldContextObject, UPlayerCharacterID* playerID, int32 loadoutIndex) {
}

void ULoadoutFunctionLibrary::RandomizeAllRandomWeaponLoadout(APlayerCharacter* Player) {
}

FLoadoutCopy ULoadoutFunctionLibrary::GetCurrentLoadout(UObject* WorldContextObject, UPlayerCharacterID* playerID) {
    return FLoadoutCopy{};
}

void ULoadoutFunctionLibrary::CopyPasteWeaponLoadout(UObject* WorldContextObject, UPlayerCharacterID* playerID, int32 fromIndex, int32 toIndex) {
}


