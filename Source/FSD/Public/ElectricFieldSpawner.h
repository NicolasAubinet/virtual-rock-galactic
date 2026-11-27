#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
#include "ElectricFieldSpawner.generated.h"

class AElectricField;
class UDamageClass;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UElectricFieldSpawner : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AElectricField> ElectricFieldClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageClass* IncendiaryDamageClass;
    
public:
    UElectricFieldSpawner(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    AElectricField* SpawnElectricField(FVector Location, FVector Normal);
    
};

