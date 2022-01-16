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

	UPROPERTY(BlueprintReadOnly) float CooldownAfterThrow;
	UPROPERTY(BlueprintReadOnly) float CooldownAfterDetonation;
	UPROPERTY(BlueprintReadOnly) float ThrowDelay;
	UPROPERTY(BlueprintReadOnly) float CooldownLeft;

	UPROPERTY(BlueprintReadOnly) TArray<AThrowableActor*> ThrownActors;

	UFUNCTION(BlueprintCallable) void Simulate_Throw(TSubclassOf<AThrowableActor> ActorClass) {}
	UFUNCTION(BlueprintCallable) void Server_Throw(TSubclassOf<AThrowableActor> ActorClass) {}

	UFUNCTION(BlueprintCallable) FVector GetThrowLocation() const { return FVector{}; }
};
