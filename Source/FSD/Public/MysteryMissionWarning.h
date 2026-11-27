#pragma once
#include "CoreMinimal.h"
#include "MissionWarning.h"
#include "MysteryMissionWarning.generated.h"

class UMysteryMissionWarning;

UCLASS(Blueprintable)
class UMysteryMissionWarning : public UMissionWarning {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HazardBonusRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UMissionWarning*, float> RollWeights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMysteryMissionWarning* DoubleWarningPartner;
    
public:
    UMysteryMissionWarning();

};

