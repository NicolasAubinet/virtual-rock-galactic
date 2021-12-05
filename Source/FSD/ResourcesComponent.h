#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CappedResource.h"
#include "ResourcesComponent.generated.h"

UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FResourceChanged, UCappedResource*, Resource, float, currentAmount);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FSD_API UResourcesComponent : public UActorComponent
{
	GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite) TArray<UCappedResource*> Resources;
    //UPROPERTY(BlueprintAssignable) FResourceChanged ResourceChanged(UCappedResource* Resource, float currentAmount) {};
};
