#pragma once
#include "CoreMinimal.h"
#include "FSDAudioComponent.h"
#include "VolumetricAudioComponent.generated.h"

class UPrimitiveComponent;
class USoundCue;
class USoundMix;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UVolumetricAudioComponent : public UFSDAudioComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* VolumetricCollider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* SoundCue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ColliderBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTrackListener;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundMix* InsideSoundMix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSnapToListenerWhenInside;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FarDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FarUpdateInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDrawDebug;
    
public:
    UVolumetricAudioComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool UpdateVolumetricLocation();
    
    UFUNCTION(BlueprintCallable)
    void SetVolumetricCollider(UPrimitiveComponent* aCollider);
    
    UFUNCTION(BlueprintCallable)
    void SetUpdateInterval(float aInterval);
    
    UFUNCTION(BlueprintCallable)
    void SetTrackingEnabled(bool aEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetSoundCue(USoundCue* aSoundCue);
    
    UFUNCTION(BlueprintCallable)
    void SetSnapToListenerWhenInside(bool aSnap);
    
    UFUNCTION(BlueprintCallable)
    void SetInsideSoundMix(USoundMix* aSoundMix);
    
    UFUNCTION(BlueprintCallable)
    void SetFarUpdateInterval(float aInterval);
    
    UFUNCTION(BlueprintCallable)
    void SetFarDistance(float aDistance);
    
    UFUNCTION(BlueprintCallable)
    void SetDrawDebug(bool aDrawDebug);
    
    UFUNCTION(BlueprintCallable)
    void SetColliderBoneName(FName aBoneName);
    
    UFUNCTION(BlueprintCallable)
    void PlayVolumetric(USoundCue* aSoundCue, UPrimitiveComponent* aCollider);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTrackingEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsListenerInside() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsListenerFarAway() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInsideSoundMixPushed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPrimitiveComponent* GetVolumetricCollider() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USoundCue* GetSoundCue() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USoundMix* GetInsideSoundMix() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDistanceToCollider() const;
    
};

