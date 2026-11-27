#pragma once
#include "CoreMinimal.h"
#include "PaintableSurfaceRatioSignatureDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPaintableSurfaceRatioSignature, float, CleanRatio);

