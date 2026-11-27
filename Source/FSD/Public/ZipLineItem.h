#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AmmoDrivenWeapon.h"
#include "ZipLineItem.generated.h"

class UDialogDataAsset;
class UMeshComponent;
class USkinEffect;

UCLASS(Abstract, Blueprintable)
class AZipLineItem : public AAmmoDrivenWeapon {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery ExcludeSurfaceTags;
    
public:
    AZipLineItem(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SkinAdditionalMeshes(USkinEffect* Skin, UMeshComponent* Mesh);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnItemSkinChanged(USkinEffect* Skin);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool CanFireWeapon(FText& FailMsg, UDialogDataAsset*& FailShout);
    
};

