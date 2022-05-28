// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Capsula.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ACapsula : public AStaticMeshActor
{
	GENERATED_BODY()
	
private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Datos", meta = (AllowPrivateAccess = "true"))
	FString CapsulaName;

public:
	ACapsula();


protected:
	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		class URandomMovementComponent_BP* MoveRandCap;

	virtual void PickUp();


	FORCEINLINE FString GetCapsulaName() const { return CapsulaName; };
	FORCEINLINE void SetCapsulaName(const FString _CapsulaName) { CapsulaName = _CapsulaName; }

};
