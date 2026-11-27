#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "PaintableStamp.h"
#include "PaintableStampArray.generated.h"

USTRUCT(BlueprintType)
struct FPaintableStampArray : public FFastArraySerializer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPaintableStamp> Items;
    
    FSD_API FPaintableStampArray();
};

