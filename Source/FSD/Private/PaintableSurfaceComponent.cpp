#include "PaintableSurfaceComponent.h"
#include "Net/UnrealNetwork.h"

UPaintableSurfaceComponent::UPaintableSurfaceComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CleanThreshold = 0.20f;
    this->InitialDirt = 1.00f;
    this->bFollowMeshGeometry = true;
    this->CleanBrushMaterial = NULL;
    this->SoapBrushMaterial = NULL;
    this->BrushRectMinParameterName = TEXT("RectMin");
    this->BrushRectMaxParameterName = TEXT("RectMax");
    this->BrushAspectParameterName = TEXT("SurfaceAspect");
    this->GrimeSplashMaterial = NULL;
    this->GrimeSplashCount = 20;
    this->GrimeSplashOffsetXParameterName = TEXT("X_Offset");
    this->GrimeSplashOffsetYParameterName = TEXT("Y_Offset");
    this->GrimeSplashAtlasVariantsPerAxis = 2;
    this->GrimeSplashRotationParameterName = TEXT("Rotation");
    this->SurfaceMaterial = NULL;
    this->MaskParameterName = TEXT("GrimeMask");
    this->OriginParameterName = TEXT("SurfaceOrigin");
    this->RightParameterName = TEXT("SurfaceRight");
    this->UpParameterName = TEXT("SurfaceUp");
    this->SizeParameterName = TEXT("SurfaceSize");
    this->ServerCleanRatio = -1.00f;
    this->MaskRenderTarget = NULL;
    this->CleanBrushMID = NULL;
    this->SoapBrushMID = NULL;
    this->GrimeSplashMID = NULL;
}

void UPaintableSurfaceComponent::SurfaceUVToWorldFrame(FVector2D UV, float NormalOffset, FVector& OutLocation, FRotator& OutRotation) const {
}

FVector UPaintableSurfaceComponent::SurfaceUVToWorld(FVector2D UV, float NormalOffset) const {
    return FVector{};
}

void UPaintableSurfaceComponent::ResetSurface(float InInitialDirt) {
}

void UPaintableSurfaceComponent::PaintSoapRect(FVector2D MinUV, FVector2D MaxUV) {
}

void UPaintableSurfaceComponent::PaintCleanRect(FVector2D MinUV, FVector2D MaxUV) {
}

bool UPaintableSurfaceComponent::IsCleanAtUV(FVector2D UV) const {
    return false;
}

bool UPaintableSurfaceComponent::HasMeshGeometry() const {
    return false;
}

FVector2D UPaintableSurfaceComponent::GetSurfaceSize() const {
    return FVector2D{};
}

FTransform UPaintableSurfaceComponent::GetSurfaceAxes() const {
    return FTransform{};
}

UTextureRenderTarget2D* UPaintableSurfaceComponent::GetMaskRenderTarget() const {
    return NULL;
}

FIntPoint UPaintableSurfaceComponent::GetGridSize() const {
    return FIntPoint{};
}

float UPaintableSurfaceComponent::GetCleanRatio() const {
    return 0.0f;
}

void UPaintableSurfaceComponent::BindMesh(UMeshComponent* Mesh, int32 MaterialIndex) {
}

void UPaintableSurfaceComponent::AddCleanRect(FVector2D MinUV, FVector2D MaxUV) {
}

void UPaintableSurfaceComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPaintableSurfaceComponent, Stamps);
    DOREPLIFETIME(UPaintableSurfaceComponent, ServerCleanRatio);
}


