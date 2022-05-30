// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereo1.h"
#include "Bala.h"
#include "Proyectil.h"
#include "RandomMovementComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/World.h"
#include "SpawnValue.h"




AEnemigoAereo1::AEnemigoAereo1()
{

	RandMove = CreateDefaultSubobject<URandomMovementComponent>(TEXT("RandomMovement"));

	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = false;
	
}

void AEnemigoAereo1::BeginPlay()
{
	Super::BeginPlay();

}

void AEnemigoAereo1::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

	SpawnCoolDown += DeltaTime;
	if (SpawnCoolDown >= NextSpawnCoolDown)
	{

	FireShot();

	SpawnCoolDown = 1.f;
	cont+=1;		

	UWorld* World = GetWorld();
	float start = World->GetTimeSeconds();

	int start1 = (int)start;

		if (start1==60) {
			BulletCont(cont);
		}

	}

}




void AEnemigoAereo1::FireShot()
{
	bCanFire = true;
	// If it's ok to fire again
	if (bCanFire == true)
	{

		// If we are pressing fire stick in a direction

		FRotator FireRotation= GetActorRotation();
		FireRotation.Yaw = 180.f;
		//const FRotator FireRotation = FireDirection.Rotation();
		// Spawn projectile at an offset from this pawn
		FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// spawn the projectile
			World->SpawnActor<ABala>(SpawnLocation, FireRotation);
		
		}

		World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEnemigoAereo1::ShotTimerExpired, FireRate);

		bCanFire = false;

	}
}

void AEnemigoAereo1::ShotTimerExpired()
{
	bCanFire = true;
}

void AEnemigoAereo1::BulletCont(int cant)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%d"), cant));
}


