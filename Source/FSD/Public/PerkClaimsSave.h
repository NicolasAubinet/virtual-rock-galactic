#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PerkClaimEntry.h"
#include "PerkClaimsSave.generated.h"

USTRUCT(BlueprintType)
struct FSD_API FPerkClaimsSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasResetPerks2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasResetPerks3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPerkReset3NoticePending;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPerkClaimEntry> PerkEntries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGuid> KnownPerkIDs;
    
public:
    FPerkClaimsSave();
};

