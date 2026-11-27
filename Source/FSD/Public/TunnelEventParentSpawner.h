#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Components/SceneComponent.h"
#include "TunnelEventParentSpawner.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTunnelEventParentSpawner : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExclusiveSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference ExclusiveSpawnTarget;
    
    UTunnelEventParentSpawner(const FObjectInitializer& ObjectInitializer);

};

