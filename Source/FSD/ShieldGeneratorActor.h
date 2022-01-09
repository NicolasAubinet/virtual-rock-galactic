#pragma once

#include "CoreMinimal.h"
#include "ThrowableActor.h"
#include "ShieldGeneratorActor.generated.h"

UCLASS()
class FSD_API AShieldGeneratorActor : public AThrowableActor
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite) float GeneratorLifetime;
};
