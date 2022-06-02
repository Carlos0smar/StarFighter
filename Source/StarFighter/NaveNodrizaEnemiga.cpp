// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveNodrizaEnemiga.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "RandomMovementComponent.h"
#include "Math/TransformNonVectorized.h"
#include "Bala.h"
#include "UObject/UObjectGlobals.h"

ANaveNodrizaEnemiga* ANaveNodrizaEnemiga::NaveNodrizaInstance = nullptr;

ANaveNodrizaEnemiga::ANaveNodrizaEnemiga()
{


	RandMove = CreateDefaultSubobject<URandomMovementComponent>(TEXT("RandomMovement"));

	ShipMeshComponent->SetWorldScale3D(FVector(2.f, 2.f, 2.f));
	//ShipMeshComponent->SetRelativeScale3D(FVector(2.f, 2.f, 2.f));
	FRotator Rotation;
	Rotation.Yaw = 180.0f;
    ShipMeshComponent->SetWorldRotation(Rotation);

	GunOffset = FVector(120.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = false;
}

ANaveNodrizaEnemiga* ANaveNodrizaEnemiga::GetNaveNodrizaInstance()
{

	if (NaveNodrizaInstance == nullptr)
	{
		NaveNodrizaInstance = NewObject<ANaveNodrizaEnemiga>();
	}

	return NaveNodrizaInstance;
}

void ANaveNodrizaEnemiga::BeginPlay()
{
	Super::BeginPlay();

}

void ANaveNodrizaEnemiga::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	SpawnCoolDown += DeltaTime;
	if (SpawnCoolDown >= NextSpawnCoolDown)
	{
		FireShot();

		SpawnCoolDown = 0.f;

	}


}


	void ANaveNodrizaEnemiga::FireShot()
	{
		bCanFire = true;
		// If it's ok to fire again
		if (bCanFire == true)
		{

			// If we are pressing fire stick in a direction

			FRotator FireRotation = GetActorRotation();
			FireRotation.Yaw = 180.f;
			//const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<ABala>(SpawnLocation, FireRotation);

				FireRotation.Yaw = 135.f;
				SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);
				World->SpawnActor<ABala>(SpawnLocation, FireRotation);

				FireRotation.Yaw = 45.f;
				SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);
				World->SpawnActor<ABala>(SpawnLocation, FireRotation);

				FireRotation.Yaw = 225.f;
				SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);
				World->SpawnActor<ABala>(SpawnLocation, FireRotation);

				FireRotation.Yaw = 310.f;
				SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);
				World->SpawnActor<ABala>(SpawnLocation, FireRotation);
			}

			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveNodrizaEnemiga::ShotTimerExpired, FireRate);

			bCanFire = false;

		}
	}

	void ANaveNodrizaEnemiga::ShotTimerExpired()
	{
		bCanFire = true;
	}