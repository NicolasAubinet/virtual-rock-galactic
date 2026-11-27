#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PerkMaintenanceEntry.generated.h"

USTRUCT(BlueprintType)
struct FPerkMaintenanceEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid PerkID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 XP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCreditClaimed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCompletionUnseen;
    
    FSD_API FPerkMaintenanceEntry();
};

