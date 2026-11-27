#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugDamageZone.generated.h"

class UBoxComponent;
class UDamageClass;

UCLASS(Blueprintable)
class FSD_API ADebugDamageZone : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* Zone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float damageAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageClass* DamageClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool VisibleInGame;
    
public:
    ADebugDamageZone(const FObjectInitializer& ObjectInitializer);

};

