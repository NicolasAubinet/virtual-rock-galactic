#pragma once

#include "CoreMinimal.h"
#include "AnimatedItem.h"
#include "RessuplyPodItem.generated.h"

UCLASS()
class FSD_API ARessuplyPodItem : public AAnimatedItem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable) void Server_Call_Resupply(FVector Location) {}
};
