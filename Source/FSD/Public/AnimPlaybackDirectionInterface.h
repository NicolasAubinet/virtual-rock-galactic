#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AnimPlaybackDirectionInterface.generated.h"

UINTERFACE(Blueprintable)
class UAnimPlaybackDirectionInterface : public UInterface {
    GENERATED_BODY()
};

class IAnimPlaybackDirectionInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsPlayingInReverse() const;
    
};

