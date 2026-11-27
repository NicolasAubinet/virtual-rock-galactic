#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugTeleportPoint.generated.h"

UCLASS(Blueprintable)
class FSD_API ADebugTeleportPoint : public AActor {
    GENERATED_BODY()
public:
    ADebugTeleportPoint(const FObjectInitializer& ObjectInitializer);

};

