#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GroundImpactShockwaveEffect.generated.h"

class APlayerCharacter;

UCLASS(Abstract, Blueprintable)
class UGroundImpactShockwaveEffect : public UObject {
    GENERATED_BODY()
public:
    UGroundImpactShockwaveEffect();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayEffect(APlayerCharacter* Character, const FVector& Location, const FRotator& Rotation, float Radius, float ImpactVelocity, bool IsFirstPerson);
    
};

