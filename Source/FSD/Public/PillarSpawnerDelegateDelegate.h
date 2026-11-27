#pragma once
#include "CoreMinimal.h"
#include "PillarSpawnerDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPillarSpawnerDelegate, AActor*, spawnedPillar);

