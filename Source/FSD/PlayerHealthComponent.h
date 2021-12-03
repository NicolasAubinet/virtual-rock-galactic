#pragma once

#include "CoreMinimal.h"
#include "HealthComponent.h"
#include "PlayerHealthComponent.generated.h"

UCLASS()
class FSD_API UPlayerHealthComponent : public UHealthComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite) float MaxHealth;
	UPROPERTY(BlueprintReadWrite) float MaxArmor;
};
