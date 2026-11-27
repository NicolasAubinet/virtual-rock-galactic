#pragma once
#include "CoreMinimal.h"
#include "OnHttpRequestCompletedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnHttpRequestCompleted, const FString&, TitleText, const FString&, ImageURL, const FString&, OnClickURL, const FString&, SteamName, const int32&, SteamID, const FString&, LiveTimestamp);

