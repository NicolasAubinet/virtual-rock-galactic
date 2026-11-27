#pragma once
#include "CoreMinimal.h"
#include "DebrisDecalItem.h"
#include "DebrisMesh.h"
#include "DebrisDecal.generated.h"

class UStaticMesh;

UCLASS(Blueprintable, EditInlineNew)
class UDebrisDecal : public UDebrisMesh {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDebrisDecalItem> Decals;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* PlaceholderMesh;
    
public:
    UDebrisDecal();

};

