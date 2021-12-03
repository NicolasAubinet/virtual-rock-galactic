#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponentBase.generated.h"

UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthChanged);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FSD_API UHealthComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(BlueprintAssignable) FOnHealthChanged OnHealthChanged;

	UFUNCTION(BlueprintCallable) float GetHealth() { return 0; }
	UFUNCTION(BlueprintCallable) float GetHealthPct() { return 0; }
};
