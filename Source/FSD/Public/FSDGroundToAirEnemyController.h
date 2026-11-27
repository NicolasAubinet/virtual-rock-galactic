#pragma once
#include "CoreMinimal.h"
#include "FSDAIController.h"
#include "FSDGroundToAirEnemyController.generated.h"

class AActor;
class UBehaviorTree;

UCLASS(Blueprintable)
class FSD_API AFSDGroundToAirEnemyController : public AFSDAIController {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBehaviorTree* BehaviourTree;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    AActor* CurrentTarget;
    
public:
    AFSDGroundToAirEnemyController(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};

