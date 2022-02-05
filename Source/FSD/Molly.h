#pragma once

#include "CoreMinimal.h"
#include "MULE.h"
#include "Molly.generated.h"

UCLASS()
class FSD_API AMolly : public AMULE
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable) void EnableButton() {}
};
