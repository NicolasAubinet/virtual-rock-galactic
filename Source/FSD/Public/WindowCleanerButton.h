#pragma once
#include "CoreMinimal.h"
#include "EWindowCleanerCommand.h"
#include "InstantUsable.h"
#include "WindowCleanerButton.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UWindowCleanerButton : public UInstantUsable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWindowCleanerCommand Command;
    
    UWindowCleanerButton(const FObjectInitializer& ObjectInitializer);

};

