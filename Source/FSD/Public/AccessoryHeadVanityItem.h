#pragma once
#include "CoreMinimal.h"
#include "HeadVanityItem.h"
#include "AccessoryHeadVanityItem.generated.h"

class UDataTable;
class UStaticMesh;

UCLASS(Blueprintable, EditInlineNew)
class UAccessoryHeadVanityItem : public UHeadVanityItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* AccessoryMeshTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> DefaultAccessoryMesh;
    
public:
    UAccessoryHeadVanityItem();

};

