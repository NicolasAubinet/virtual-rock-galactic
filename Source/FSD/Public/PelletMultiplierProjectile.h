#pragma once
#include "CoreMinimal.h"
#include "Projectile.h"
#include "PelletMultiplierProjectile.generated.h"

UCLASS(Abstract, Blueprintable)
class APelletMultiplierProjectile : public AProjectile {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpectedHitRateDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpectedHitRateStagger;
    
public:
    APelletMultiplierProjectile(const FObjectInitializer& ObjectInitializer);

};

