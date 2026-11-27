#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AccessoryMeshRow.generated.h"

class UBeardColorVanityItem;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FAccessoryMeshRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBeardColorVanityItem* HairColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> AccessoryMesh;
    
    FSD_API FAccessoryMeshRow();
};

