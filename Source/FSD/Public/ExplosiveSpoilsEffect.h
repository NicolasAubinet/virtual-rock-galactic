#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "ExplosiveSpoilsEffect.generated.h"

class UMaterialInstance;
class UTerrainMaterial;

UCLASS(Abstract, Blueprintable)
class UExplosiveSpoilsEffect : public UObject {
    GENERATED_BODY()
public:
    UExplosiveSpoilsEffect();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayEffect(const FVector& Location, UMaterialInstance* DebrisMaterial, UTerrainMaterial* RockMaterial);
    
};

