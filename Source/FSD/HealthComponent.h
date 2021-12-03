#pragma once

#include "CoreMinimal.h"
#include "HealthComponentBase.h"
#include "HealthComponent.generated.h"

UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnArmorChanged);

UCLASS()
class FSD_API UHealthComponent : public UHealthComponentBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable) FOnArmorChanged OnArmorChanged;

	UFUNCTION(BlueprintCallable) float GetArmor() { return 0; }
	UFUNCTION(BlueprintCallable) float GetArmorPct() { return 0; }
};
