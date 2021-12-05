#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ResourceData.h"
#include "CappedResource.generated.h"

UCLASS()
class FSD_API UCappedResource : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite) float currentAmount;
	UPROPERTY(BlueprintReadWrite) UResourceData* Data;
};
