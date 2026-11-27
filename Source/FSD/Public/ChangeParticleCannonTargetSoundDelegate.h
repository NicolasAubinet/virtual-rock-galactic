#pragma once
#include "CoreMinimal.h"
#include "ETargetSound.h"
#include "ChangeParticleCannonTargetSoundDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChangeParticleCannonTargetSound, ETargetSound, TargetSound);

