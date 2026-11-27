#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "AnimatedItem.h"
#include "EPlaceableObstructionType.h"
#include "PlaceableInterface.h"
#include "Templates/SubclassOf.h"
#include "CableBuilderItem.generated.h"

class ACable;
class ACableEnd;
class UCableUsable;
class UCrosshairAggregator;
class UItemPlacerAggregator;

UCLASS(Blueprintable)
class FSD_API ACableBuilderItem : public AAnimatedItem, public IPlaceableInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCrosshairAggregator* CrosshairAggregator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemPlacerAggregator* CablePlacer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlaceableObstructionType ObstructionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ObstructionLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector GroundNormal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACable> DefaultCableType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Cable, meta=(AllowPrivateAccess=true))
    ACable* Cable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool bIsPlacingCable;
    
public:
    ACableBuilderItem(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UpdatePlacement(const FTransform& InTransform, ACableEnd* InCableEnd, bool bPlacementValid, bool InUpdateServer);
    
protected:
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void ServerUpdatePlacement(const FTransform& InTransform, const bool bPlacementValid, ACableEnd* InCableEnd);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerFinishPlacement(const FTransform& FinalLocation, ACableEnd* CableEnd);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerCancelPlacement();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerBeginPlaceCable(UCableUsable* InUsable);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivePlacementUpdated(bool InCanPlace, bool InConnecting, float InDistanceProgress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveBeginPlaceCable();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Cable();
    
public:
    UFUNCTION(BlueprintCallable)
    void FinishPlacement(const FTransform& FinalLocation, ACableEnd* CableEnd);
    
    UFUNCTION(BlueprintCallable)
    void CancelPlacement();
    

    // Fix for true pure virtual functions not being implemented
};

