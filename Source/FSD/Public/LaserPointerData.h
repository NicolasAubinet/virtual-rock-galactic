#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ELaserPointerTargetType.h"
#include "LaserPointerData.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FLaserPointerData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    FText Name;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FLinearColor Color;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    UTexture2D* Icon;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ELaserPointerTargetType TargetType;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FGuid SaveGameID;
    
    FSD_API FLaserPointerData();
};

