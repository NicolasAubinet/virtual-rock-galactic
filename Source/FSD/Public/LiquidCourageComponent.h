#pragma once
#include "CoreMinimal.h"
#include "FloatPerkComponent.h"
#include "LiquidCourageComponent.generated.h"

class AItem;
class AMissionDrinkItem;
class UItemID;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ULiquidCourageComponent : public UFloatPerkComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemID* DrinkItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AMissionDrinkItem* DrinkItemInstance;
    
public:
    ULiquidCourageComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnDrinkItemInstanced(AItem* itemInstance);
    
    UFUNCTION(BlueprintCallable)
    void OnDrinkItemChargesChanged(int32 newCharges);
    
};

