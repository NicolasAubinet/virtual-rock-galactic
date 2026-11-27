#pragma once
#include "CoreMinimal.h"
#include "MonitoringStationAlarmBorder.generated.h"

USTRUCT(BlueprintType)
struct FMonitoringStationAlarmBorder {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BorderName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ParameterName;
    
    FSD_API FMonitoringStationAlarmBorder();
};

