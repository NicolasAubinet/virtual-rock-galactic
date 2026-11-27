#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VolumetricAudioActor.generated.h"

class UBoxComponent;
class UVolumetricAudioComponent;

UCLASS(Blueprintable)
class AVolumetricAudioActor : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* Box;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVolumetricAudioComponent* VolumetricAudio;
    
public:
    AVolumetricAudioActor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UVolumetricAudioComponent* GetVolumetricAudio() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBoxComponent* GetBox() const;
    
};

