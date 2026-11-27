#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "HitscanComponent.h"
#include "CoilgunRicochetHitscanComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UCoilgunRicochetHitscanComponent : public UHitscanComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxRicochets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnemyPenetrationDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SurfaceOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer DeprioritizedTargetTags;
    
public:
    UCoilgunRicochetHitscanComponent(const FObjectInitializer& ObjectInitializer);

};

