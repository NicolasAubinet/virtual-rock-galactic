#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SmartClusterAimComponent.generated.h"

class AProjectile;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API USmartClusterAimComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SearchRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerSafetyMargin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SharedTargetSpreadAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AltitudeWeight;
    
public:
    USmartClusterAimComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AimClusters(const TArray<AProjectile*>& Clusters);
    
};

