#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "DualWieldWeapon.generated.h"

class UAnimMontage;
class UFirstPersonSkeletalMeshComponent;
class USkeletalMeshComponent;
class UFXSystemAsset;

UCLASS(Abstract)
class ADualWieldWeapon : public AAmmoDrivenWeapon {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere)
    UFirstPersonSkeletalMeshComponent* FPMeshLeft;
    
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere)
    USkeletalMeshComponent* TPMeshLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAnimMontage* WPN_Left_Reload;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAnimMontage* WPN_Left_TP_Reload;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UFXSystemAsset* CasingParticlesLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName MuzzleLeft;
    
public:
    ADualWieldWeapon();
};

