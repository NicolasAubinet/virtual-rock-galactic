#pragma once
#include "CoreMinimal.h"
#include "Sound/SoundEffectSource.h"
#include "FSDTremoloSettings.h"
#include "FSDTremoloPreset.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class FSD_API UFSDTremoloPreset : public USoundEffectSourcePreset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFSDTremoloSettings Settings;
    
    UFSDTremoloPreset();

    UFUNCTION(BlueprintCallable)
    void SetSettings(const FFSDTremoloSettings& InSettings);
    
};

