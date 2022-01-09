#pragma once

#include "CoreMinimal.h"
#include "AnimatedItem.h"
#include "ThrowableItem.generated.h"

class AThrowableActor;

UCLASS()
class FSD_API AThrowableItem : public AAnimatedItem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable) void Server_Throw(AThrowableActor* ActorClass) {}
	UFUNCTION(BlueprintCallable) FVector GetThrowLocation() const { return FVector{}; }
};
