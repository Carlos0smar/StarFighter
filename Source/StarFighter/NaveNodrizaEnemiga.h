// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "NaveNodrizaEnemiga.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveNodrizaEnemiga : public ANave
{
	GENERATED_BODY()

public:
	
	ANaveNodrizaEnemiga();



	UPROPERTY()
		class URandomMovementComponent* RandMove;



	uint32 bCanFire : 1;

	FTimerHandle TimerHandle_ShotTimerExpired;


	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	float NextSpawnCoolDown = 2.0f;
	float SpawnCoolDown = 0.0f;

	void FireShot();

	void ShotTimerExpired();
};
