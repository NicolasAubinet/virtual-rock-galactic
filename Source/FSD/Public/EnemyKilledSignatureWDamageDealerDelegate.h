#pragma once
#include "CoreMinimal.h"
#include "EnemyKilledSignatureWDamageDealerDelegate.generated.h"

class AActor;
class UDamageClass;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEnemyKilledSignatureWDamageDealer, UDamageClass*, DamageClass, AActor*, damageDealer);

