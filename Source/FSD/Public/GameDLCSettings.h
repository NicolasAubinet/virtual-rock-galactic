#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameDLCSettings.generated.h"

class UGameDLC;
class UObject;

UCLASS(Blueprintable)
class FSD_API UGameDLCSettings : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<UGameDLC*> StoreDLCs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameDLC* CurrentAdvertisedDLC;
    
public:
    UGameDLCSettings();

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    TArray<UGameDLC*> GetStoreDLCs(UObject* WorldContext);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    TArray<UGameDLC*> GetAnnouncableDLCs(UObject* WorldContext);
    
};

