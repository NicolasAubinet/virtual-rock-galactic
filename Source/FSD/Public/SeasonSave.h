#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SeasonSaveEntry.h"
#include "SeasonSave.generated.h"

USTRUCT(BlueprintType)
struct FSeasonSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SchematicsFixedUpInSeasonFive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasFixedUpRewardsRemovedInSeasonFiveV2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasFixedUpSeason3EventScripClaimed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasFixedUpSeason3And4EventScripClaimedToGeneralization;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FSeasonSaveEntry> Seasons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ActiveSeason;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DesiredSeason;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasSeenSeason7;
    
public:
    FSD_API FSeasonSave();
};

