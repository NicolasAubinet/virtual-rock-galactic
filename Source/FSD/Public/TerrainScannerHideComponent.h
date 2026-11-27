#pragma once
#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "TerrainScannerHideComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UTerrainScannerHideComponent : public USphereComponent {
    GENERATED_BODY()
public:
    UTerrainScannerHideComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void DoHide();
    
};

