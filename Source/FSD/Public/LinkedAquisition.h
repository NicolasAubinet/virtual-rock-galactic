#pragma once
#include "CoreMinimal.h"
#include "ItemAquisitionBase.h"
#include "LinkedAquisition.generated.h"

class UVanityItem;

UCLASS(Blueprintable, EditInlineNew)
class FSD_API ULinkedAquisition : public UItemAquisitionBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVanityItem* PrimaryItem;
    
public:
    ULinkedAquisition();

};

