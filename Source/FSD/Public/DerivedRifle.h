#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AmmoDrivenWeapon.h"
#include "DerivedRifle.generated.h"

class UStatusEffect;
class AActor;
class UFSDPhysicalMaterial;

UCLASS(Blueprintable)
class ADerivedRifle : public AAmmoDrivenWeapon {
    GENERATED_BODY()
public:
protected:
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    //float KillsResetAccuracyDuration;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    //bool KillsTriggersStatusEffect;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    //TSubclassOf<UStatusEffect> KillTriggeredStatusEffect;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool DerivedVarBool;
    
public:
    ADerivedRifle();
protected:
    //UFUNCTION(BlueprintCallable)
    //void OnTimerElapsed();
    
    //UFUNCTION(BlueprintCallable)
    //void OnEnemyKilled(AActor* Target, UFSDPhysicalMaterial* PhysMat, bool wasDirectHit);
    
    //UFUNCTION(BlueprintCallable, Client, Reliable)
    //void Client_ResetAccuracy();
    
};
