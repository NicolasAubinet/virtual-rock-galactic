#pragma once
#include "CoreMinimal.h"
#include "MeshCarverComponent.h"
#include "RandomMeshCarverComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URandomMeshCarverComponent : public UMeshCarverComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarveChance;
    
    URandomMeshCarverComponent(const FObjectInitializer& ObjectInitializer);

};

