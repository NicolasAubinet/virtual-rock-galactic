#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TunnelEventActorSpawner.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UTunnelEventActorSpawner : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> ToSpawn;
    
    UTunnelEventActorSpawner(const FObjectInitializer& ObjectInitializer);

};

