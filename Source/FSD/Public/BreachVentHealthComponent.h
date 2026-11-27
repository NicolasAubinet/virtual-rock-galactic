#pragma once
#include "CoreMinimal.h"
#include "SimpleHealthComponent.h"
#include "BreachVentHealthComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UBreachVentHealthComponent : public USimpleHealthComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IgnorePlayerDamage;
    
public:
    UBreachVentHealthComponent(const FObjectInitializer& ObjectInitializer);

};

