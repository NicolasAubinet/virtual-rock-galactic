#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ResourceData.generated.h"

UCLASS()
class FSD_API UResourceData : public UDataAsset
{
	GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite) FText Title;
};
