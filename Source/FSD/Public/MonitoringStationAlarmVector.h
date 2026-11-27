#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MonitoringStationAlarmVector.generated.h"

USTRUCT(BlueprintType)
struct FMonitoringStationAlarmVector {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ColorA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ColorB;
    
    FSD_API FMonitoringStationAlarmVector();
};

