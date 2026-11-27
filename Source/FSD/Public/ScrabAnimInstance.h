#pragma once
#include "CoreMinimal.h"
#include "EScrabDeathAnimationCategory.h"
#include "FlyingBugAnimInstance.h"
#include "ScrabAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UScrabAnimInstance : public UFlyingBugAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsFlying;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsFlyingAndMoving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsFlyingAndNotMoving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EScrabDeathAnimationCategory ScrabDeathAnimationCategory;
    
public:
    UScrabAnimInstance();

    UFUNCTION(BlueprintCallable)
    void SetScrabDeathAnimationCategory(EScrabDeathAnimationCategory Category);
    
};

