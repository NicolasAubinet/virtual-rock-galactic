#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MaterialDebugProbe.generated.h"

class UCameraComponent;

UCLASS(Blueprintable)
class FSD_API AMaterialDebugProbe : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceInterval;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCameraComponent* TargetCamera;
    
public:
    AMaterialDebugProbe(const FObjectInitializer& ObjectInitializer);

};

