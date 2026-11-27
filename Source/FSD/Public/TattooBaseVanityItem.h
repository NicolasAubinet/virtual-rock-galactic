#pragma once
#include "CoreMinimal.h"
#include "ETattooLocation.h"
#include "VanityItem.h"
#include "TattooBaseVanityItem.generated.h"

class AFSDPlayerState;
class UVanityTattoo;

UCLASS(Blueprintable, EditInlineNew)
class UTattooBaseVanityItem : public UVanityItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UVanityTattoo> Tattoo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FlipTexture;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETattooLocation TattooLocation;
    
public:
    UTattooBaseVanityItem();

    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void PreviewTattoo(AFSDPlayerState* PlayerState, bool Show) const;
    
};

