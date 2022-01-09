#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MissionGenerationManager.generated.h"

class UGeneratedMission;

UCLASS()
class FSD_API UMissionGenerationManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable) TArray<UGeneratedMission*> GetAvailableMissions() { return TArray<UGeneratedMission*>(); }
};
