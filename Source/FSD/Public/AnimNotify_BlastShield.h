#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_BlastShield.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class FSD_API UAnimNotify_BlastShield : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventName;
    
    UAnimNotify_BlastShield();

};

