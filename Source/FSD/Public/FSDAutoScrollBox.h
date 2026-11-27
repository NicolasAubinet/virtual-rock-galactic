#pragma once
#include "CoreMinimal.h"
#include "Components/ScrollBox.h"
#include "FSDAutoScrollBox.generated.h"

UCLASS(Blueprintable)
class UFSDAutoScrollBox : public UScrollBox {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScrollSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PauseTime;
    
    UFSDAutoScrollBox();

};

