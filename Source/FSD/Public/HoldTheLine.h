#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Templates/SubclassOf.h"
#include "HoldTheLine.generated.h"

class APlayerCharacter;
class UPawnStat;
class UStatusEffect;

UCLASS(Blueprintable)
class UHoldTheLine : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UHoldTheLine();

    UFUNCTION(BlueprintCallable)
    static void RefreshDamageResistance(APlayerCharacter* PlayerCharacter, const TArray<APlayerCharacter*>& InPlayersNearbyArray, UPawnStat* PawnStat, float DamageResistance, float OthersDamageResistance, TSubclassOf<UStatusEffect> StatusEffect);
    
    UFUNCTION(BlueprintCallable)
    static void CheckPlayerDistance(APlayerCharacter* PlayerCharacter, float DistanceCompare, UPawnStat* PawnStat, float DamageResistance, float OthersDamageResistance, const TArray<APlayerCharacter*>& InPlayersNearbyArray, TArray<APlayerCharacter*>& OutPlayersNearbyArray, TSubclassOf<UStatusEffect> StatusEffect);
    
};

