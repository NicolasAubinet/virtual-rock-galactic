#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HoopScoreWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UHoopScoreWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UHoopScoreWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetScore(int32 Score);
    
};

