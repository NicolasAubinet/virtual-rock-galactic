#include "HoldTheLine.h"
#include "Templates/SubclassOf.h"

UHoldTheLine::UHoldTheLine() {
}

void UHoldTheLine::RefreshDamageResistance(APlayerCharacter* PlayerCharacter, const TArray<APlayerCharacter*>& InPlayersNearbyArray, UPawnStat* PawnStat, float DamageResistance, float OthersDamageResistance, TSubclassOf<UStatusEffect> StatusEffect) {
}

void UHoldTheLine::CheckPlayerDistance(APlayerCharacter* PlayerCharacter, float DistanceCompare, UPawnStat* PawnStat, float DamageResistance, float OthersDamageResistance, const TArray<APlayerCharacter*>& InPlayersNearbyArray, TArray<APlayerCharacter*>& OutPlayersNearbyArray, TSubclassOf<UStatusEffect> StatusEffect) {
}


