// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Capsula.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ACapsula : public AActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Datos", meta = (AllowPrivateAccess = "true"))
	FString CapsulaName;

public:
	ACapsula();


	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* ShipMeshComponent;

//	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Datos", meta = (AllowPrivateAccess = "true"))
//		float MenosVida;


protected:
	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;


	UPROPERTY()
		class URandomMovementComponent_BP* MoveRandCap;

	virtual void PickUp();
	virtual void Generar();
//	FORCEINLINE float GetMenosVida(float quitar){ return quitar -= 5; };

	FString GetCapsulaName() { return CapsulaName; };
	void SetCapsulaName(const FString _CapsulaName) { CapsulaName = _CapsulaName; }

};
