// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "RandomMovementComponent.h"
#include "EnemigoAereo1.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AEnemigoAereo1 : public ANave
{
	GENERATED_BODY()

public:

	AEnemigoAereo1();

	uint32 bCanFire : 1;
	
	int cont = 0;

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
	
	float NextSpawnCoolDown = 2.0f;
	float SpawnCoolDown = 0.0f;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float MoveSpeed;


	UPROPERTY()
		class URandomMovementComponent* RandMove;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;
	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	/* Fire a shot in the specified direction */
	void FireShot();

	UPROPERTY(EditAnywhere)
		USceneComponent* BulletSpawnPoint;

	UPROPERTY(EditAnywhere, Category = "Component")
		class UProjectileMovementComponent* ProjectileMove;


	
	//void Fire();
	void ShotTimerExpired();

	void BulletCont(int cont);
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
};
