#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "CablePoint.h"
#include "ETrackBuildPlacementState.h"
#include "Cable.generated.h"

class ACableEnd;
class AItem;
class APlayerCharacter;
class UCableUsable;
class USceneComponent;
class USplineComponent;
class USplineMeshComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class FSD_API ACable : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACableEnd* DesignatedCableEnd;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineMeshComponent* CableSplineMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* CableSplineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* CableEndPostMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* PreviewEndPostLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> BuiltByCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UCableUsable> BuiltFromUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCablePoint CableEndTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CableEndTransform, meta=(AllowPrivateAccess=true))
    FCablePoint ServerCableEndTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxLength;
    
public:
    ACable(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    bool UpdatePlacement(const FTransform& InTransform, ACableEnd* InCableEnd, AItem* PlaceableItem);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivePlacementValidChanged(bool InIsValid);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivePlacementStateChanged(ETrackBuildPlacementState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivePlacementChangedEnd(const FTransform& NewEndTransform, ACableEnd* InCableEnd);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivePlacementChangedBegin(const FTransform& NewEndTransform, ACableEnd* InCableEnd);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ReceiveCanPlaceAt(const FTransform& InCandidateTransform, ACableEnd* InCableEnd);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CableEndTransform();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ETrackBuildPlacementState GetPlacementState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsCableEndTransformValid() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetCableEndTransform() const;
    
    UFUNCTION(BlueprintCallable)
    bool CanPlaceAt(const FTransform& InCandidateTransform, ACableEnd* InCableEnd, AItem* PlaceableItem);
    
};

