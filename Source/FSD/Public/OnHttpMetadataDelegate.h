#pragma once
#include "CoreMinimal.h"
#include "OnHttpMetadataDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHttpMetadata, const FString&, CurrentGuid);

