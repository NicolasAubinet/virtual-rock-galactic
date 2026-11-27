#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/SceneComponent.h"
#include "PaintableStampArray.h"
#include "PaintableSurfaceRatioSignatureDelegate.h"
#include "PaintableSurfaceSignatureDelegate.h"
#include "PaintableSurfaceComponent.generated.h"

class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMeshComponent;
class UTextureRenderTarget2D;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UPaintableSurfaceComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPaintableSurfaceRatioSignature OnCleanRatioChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPaintableSurfaceSignature OnFullyCleaned;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D SurfaceSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CleanThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialDirt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFollowMeshGeometry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* CleanBrushMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* SoapBrushMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BrushRectMinParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BrushRectMaxParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BrushAspectParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* GrimeSplashMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GrimeSplashCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D GrimeSplashSizeRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GrimeSplashOffsetXParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GrimeSplashOffsetYParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GrimeSplashAtlasVariantsPerAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GrimeSplashRotationParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* SurfaceMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MaskParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OriginParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RightParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UpParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SizeParameterName;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FPaintableStampArray Stamps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float ServerCleanRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* MaskRenderTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* CleanBrushMID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* SoapBrushMID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* GrimeSplashMID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> BoundMIDs;
    
public:
    UPaintableSurfaceComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    void SurfaceUVToWorldFrame(FVector2D UV, float NormalOffset, FVector& OutLocation, FRotator& OutRotation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector SurfaceUVToWorld(FVector2D UV, float NormalOffset) const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ResetSurface(float InInitialDirt);
    
    UFUNCTION(BlueprintCallable)
    void PaintSoapRect(FVector2D MinUV, FVector2D MaxUV);
    
    UFUNCTION(BlueprintCallable)
    void PaintCleanRect(FVector2D MinUV, FVector2D MaxUV);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCleanAtUV(FVector2D UV) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasMeshGeometry() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetSurfaceSize() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetSurfaceAxes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTextureRenderTarget2D* GetMaskRenderTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetGridSize() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCleanRatio() const;
    
    UFUNCTION(BlueprintCallable)
    void BindMesh(UMeshComponent* Mesh, int32 MaterialIndex);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AddCleanRect(FVector2D MinUV, FVector2D MaxUV);
    
};

