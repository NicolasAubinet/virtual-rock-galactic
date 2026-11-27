#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "OnHttpMetadataDelegate.h"
#include "BannerMetadata.generated.h"

class UBannerMetadata;
class UObject;

UCLASS(Blueprintable, Config=Game)
class UBannerMetadata : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHttpMetadata success;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHttpMetadata Failure;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ConsoleGuid;
    
    UBannerMetadata();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UBannerMetadata* DownloadMetadata(UObject* WorldContextObject, const FString& InMetadataValue);
    
};

