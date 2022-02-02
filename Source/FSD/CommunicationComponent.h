#pragma once

#include "CoreMinimal.h"
#include "FSD_struct.h"
#include "Components/ActorComponent.h"
#include "CommunicationComponent.generated.h"

class UDialogDataAsset;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FSD_API UCommunicationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void Shout(EShoutType Shout) {}
};
