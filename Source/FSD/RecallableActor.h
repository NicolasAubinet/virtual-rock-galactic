#pragma once

#include "CoreMinimal.h"
#include "DeepPathfinderCharacter.h"
#include "RecallableActor.generated.h"

UCLASS()
class FSD_API ARecallableActor : public ADeepPathfinderCharacter
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable) void Relocate(FVector NewLocation, FRotator NewRotation) {}
	UFUNCTION(BlueprintCallable) void Recall() {}
};
