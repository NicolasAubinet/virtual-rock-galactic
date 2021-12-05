#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "TeamResourcesComponent.h"
#include "FSDGameState.generated.h"

UCLASS()
class FSD_API AFSDGameState : public AGameState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite) UTeamResourcesComponent* TeamResources;
};
