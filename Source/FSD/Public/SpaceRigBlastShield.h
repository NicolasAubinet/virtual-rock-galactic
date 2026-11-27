#pragma once
#include "CoreMinimal.h"
#include "Animation/SkeletalMeshActor.h"
#include "AnimPlaybackDirectionInterface.h"
#include "SpaceRigBlastShield.generated.h"

class UAnimSequenceBase;

UCLASS(Blueprintable)
class FSD_API ASpaceRigBlastShield : public ASkeletalMeshActor, public IAnimPlaybackDirectionInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequenceBase* ShieldAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequenceBase* OpenAnimation;
    
    ASpaceRigBlastShield(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnShieldAnimNotify(FName EventName);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnShieldAnimationStarted(bool bClosing);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnShieldAnimationFinished(bool bClosing);
    

    // Fix for true pure virtual functions not being implemented
};

