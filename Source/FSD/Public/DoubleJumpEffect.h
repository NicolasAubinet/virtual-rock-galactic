#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DoubleJumpEffect.generated.h"

class APlayerCharacter;

UCLASS(Abstract, Blueprintable)
class UDoubleJumpEffect : public UObject {
    GENERATED_BODY()
public:
    UDoubleJumpEffect();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayEffect(APlayerCharacter* Character, int32 Stage);
    
};

