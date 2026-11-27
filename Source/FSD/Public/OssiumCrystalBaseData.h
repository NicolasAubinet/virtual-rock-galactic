#pragma once
#include "CoreMinimal.h"
#include "OssiumCrystalBaseData.generated.h"

class UStaticMeshCarver;

USTRUCT(BlueprintType)
struct FOssiumCrystalBaseData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMeshCarver> Dirt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMeshCarver> Bone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMeshCarver> CrystalTransition;
    
    FSD_API FOssiumCrystalBaseData();
};

