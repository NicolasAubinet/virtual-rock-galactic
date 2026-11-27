#pragma once
#include "CoreMinimal.h"
#include "ItemUpgrade.h"
#include "StandardItemUpgrade.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UStandardItemUpgrade : public UItemUpgrade {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float amount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OverrideValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CosmeticOnly;
    
public:
    UStandardItemUpgrade();

};

