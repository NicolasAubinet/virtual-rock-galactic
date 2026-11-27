#pragma once
#include "CoreMinimal.h"
#include "InstantUsable.h"
#include "DepressurerizationLidUsable.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UDepressurerizationLidUsable : public UInstantUsable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText OpenText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CloseText;
    
    UDepressurerizationLidUsable(const FObjectInitializer& ObjectInitializer);

};

