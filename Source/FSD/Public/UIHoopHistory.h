#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIHoopHistory.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UUIHoopHistory : public UUserWidget {
    GENERATED_BODY()
public:
    UUIHoopHistory();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateScores(const TArray<int32>& Scores);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    int32 GetHistoryCount() const;
    
};

