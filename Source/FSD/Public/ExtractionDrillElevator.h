#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ExtractionDrillElevator.generated.h"

class UStaticMeshComponent;

UCLASS(Blueprintable)
class FSD_API AExtractionDrillElevator : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* PlatformMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TravelDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BottomDwellDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TopDwellDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ShaftEnds, meta=(AllowPrivateAccess=true))
    FVector ShaftBottom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ShaftEnds, meta=(AllowPrivateAccess=true))
    FVector ShaftTop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float PhaseOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Running, meta=(AllowPrivateAccess=true))
    bool bRunning;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float StopTime;
    
public:
    AExtractionDrillElevator(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetShaftEnds(const FVector& Bottom, const FVector& Top);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetRunning(bool running);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnShaftDeployed(const FVector& Bottom, const FVector& Top);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_ShaftEnds();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Running();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintNativeEvent)
    void OnElevatorAlpha(float alpha);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRunning() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDwelling() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasShaftEnds() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetShaftTop() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetShaftBottom() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStaticMeshComponent* GetPlatformMesh() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetPlatformLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetElevatorAlpha() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DeployInShaft();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void CaptureShaftTop();
    
};

