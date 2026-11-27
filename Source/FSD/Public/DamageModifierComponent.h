#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageModifierComponent.generated.h"

class UDamageModifierBase;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UDamageModifierComponent : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDamageModifierBase*> DamageModifiers;
    
public:
    UDamageModifierComponent(const FObjectInitializer& ObjectInitializer);

};

