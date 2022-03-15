#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AnimatedItem.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ELaserPointerTargetType.h"
#include "Engine/EngineTypes.h"
#include "LaserPointerData.h"
#include "UObject/NoExportTypes.h"
#include "ELaserPointerMarkerType.h"
#include "UObject/NoExportTypes.h"
#include "LaserPointerItem.generated.h"

class AActor;
class ALaserPointerMarker;
class UDialogDataAsset;
class ALaserPointerWaypoint;
class USceneComponent;
class UObjectInfoComponent;
class UTerrainMaterial;
class AFSDGameState;
class UObject;
class UPrimitiveComponent;
class UTexture2D;
class UHealthComponentBase;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FLaserPointerItemOnMarkerPlaced, FVector, Location, const FText&, Name, FLinearColor, Color, AActor*, Target, ELaserPointerTargetType, TypeOfTarget);

UCLASS(Abstract)
class ALaserPointerItem : public AAnimatedItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FLaserPointerItemOnMarkerPlaced OnMarkerPlaced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<ALaserPointerMarker> MarkerType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<ALaserPointerMarker> SecondaryMarkerType;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<ALaserPointerMarker> ActiveMarker;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<ALaserPointerWaypoint> WaypointType;
    
    UPROPERTY(EditAnywhere)
    int32 MaxWaypoints;
    
    UPROPERTY(Transient)
    TArray<ALaserPointerWaypoint*> Waypoints;
    
    UPROPERTY(Transient)
    int32 NextWaypointIndex;
    
    UPROPERTY(EditAnywhere)
    float MarkerLifeTime;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FLinearColor ColorMinerals;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FLinearColor ColorEnemy;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FLinearColor ColorOther;
    
    UPROPERTY(EditAnywhere)
    UDialogDataAsset* DefaultLookAtShout;
    
    UPROPERTY(EditAnywhere)
    UDialogDataAsset* DefaultEnemyShout;
    
    UPROPERTY(BlueprintReadOnly, Export, VisibleAnywhere)
    USceneComponent* PointerComponent;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FHitResult LookAtHit;
    
    UPROPERTY(BlueprintReadWrite, Export, Transient)
    TWeakObjectPtr<UObjectInfoComponent> LookAtInfo;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<UTerrainMaterial> LookAtTerrainMaterial;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FLaserPointerData LookAtData;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LookAtDistance;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    UDialogDataAsset* LookAtShout;
    
    UPROPERTY(Transient)
    AFSDGameState* GameState;
    
    UFUNCTION(BlueprintCallable)
    void UnlockToMinersManual(UObject* WorldContextObject, FGuid ObjectID);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ToggleLaserVisible(bool aVisible);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPlaceMarker(FVector Location, AActor* Actor, UPrimitiveComponent* Cmponent, UTerrainMaterial* TerrainMaterial, ELaserPointerMarkerType eMarkerType);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SecondaryUse();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPointOfInterest(AActor* TargetActor, FVector TargetLocation, UTexture2D* TargetIcon);
    
    UFUNCTION(BlueprintCallable)
    void OnDeath(UHealthComponentBase* Health);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    void GetPointTransform(FTransform& PointTransform);
    
    ALaserPointerItem();
};

