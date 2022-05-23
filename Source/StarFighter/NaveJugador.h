// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "InvetoryComponent.h"
#include "NaveJugador.generated.h"

/**
 * 
 */

UCLASS()
class STARFIGHTER_API ANaveJugador : public ANave
{
	GENERATED_BODY()
	
		/** The camera */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

public:

	ANaveJugador();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	/* Flag to control firing  */
	uint32 bCanFire : 1;


	void Fire();

	/* Fire a shot in the specified direction */
	void FireShot(FVector FireDirection);


	/* Handler for the fire timer expiry */
	void ShotTimerExpired();

	UFUNCTION()
		void TakeItem(ACapsula* InventoryItem);

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float MoveSpeed;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float Energy;

	UFUNCTION()
		virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;



	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;
	static const FName FireBinding;

	UPROPERTY()
	  UInvetoryComponent* ShipInventory;

	UFUNCTION()
		void Lista();

	UPROPERTY()
		TMap<FString, int32> Datos;


	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	float FireForwardValue;
	float FireRightValue;
};
