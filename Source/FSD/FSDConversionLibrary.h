// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FSDConversionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class FSD_API UFSDConversionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable)
		static FVector_NetQuantizeNormal VectorToNetQuantizeNormal(FVector Vec) { FVector_NetQuantizeNormal dummyvec; return dummyvec; };
};
