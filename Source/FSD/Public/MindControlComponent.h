#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MindControlComponent.generated.h"

class AActor;
class UBehaviorTree;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMindControlComponent : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBehaviorTree* CachedTree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Instigator;
    
public:
    UMindControlComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetInstigator() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBehaviorTree* GetCachedTree() const;
    
};

