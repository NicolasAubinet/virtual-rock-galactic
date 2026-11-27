#pragma once
#include "CoreMinimal.h"
#include "PerkMaintenanceEntry.h"
#include "PerkMaintenance.generated.h"

USTRUCT(BlueprintType)
struct FSD_API FPerkMaintenance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPerkMaintenanceEntry> Entries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BonusPerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStarterBonusGranted;
    
public:
    FPerkMaintenance();
};

