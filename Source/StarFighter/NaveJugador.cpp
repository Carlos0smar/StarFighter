// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/CollisionProfile.h"
#include "NaveJugador.h"
#include "Bala.h"
#include "Capsula.h"

const FName ANaveJugador::MoveForwardBinding("MoveForward");
const FName ANaveJugador::MoveRightBinding("MoveRight");
const FName ANaveJugador::FireBinding("Fire");

ANaveJugador::ANaveJugador()
{

	//Cap = CreateDefaultSubobject<UCapsula>(TEXT("Cpasula"));

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	ShipInventory = CreateDefaultSubobject<UInvetoryComponent>("MyInventory");


	MoveSpeed = 1000.0f;
	Energy = 100.0f;

	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = false;

	FireForwardValue = 1.0f;
	FireRightValue = 0.0f;

	//Datos de la nave
	Datos.Add("Velocidad", 0);
	Datos.Add("Vida", 5);
	Datos.Add("ArmaFuncional", 0);


}

void ANaveJugador::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	//PlayerInputComponent->BindAction(Fire)
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ANaveJugador::Fire);

	PlayerInputComponent->BindAction(TEXT("Lista"), IE_Pressed, this, &ANaveJugador::Lista);

}

void ANaveJugador::BeginPlay()
{
	Super::BeginPlay();
}

void ANaveJugador::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	if (ForwardValue != 0.0f || RightValue != 0.0f) {

		if (ForwardValue != FireForwardValue) {
			FireForwardValue = ForwardValue;
		}

		if (RightValue != FireRightValue) {
			FireRightValue = RightValue;
		}
	}

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}

}

void ANaveJugador::Fire() {
	bCanFire = true;
	UE_LOG(LogTemp, Warning, TEXT("Se presiono la barra espaciadora"));
	// Create fire direction vector

	UE_LOG(LogTemp, Warning, TEXT("FireForwardValue: %f FireRightValue: %f"), FireForwardValue, FireRightValue);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Try and fire a shot
	FireShot(FireDirection);
}


void ANaveJugador::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{

		const FRotator FireRotation = FireDirection.Rotation();
		// Spawn projectile at an offset from this pawn
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// spawn the projectile
			World->SpawnActor<ABala>(SpawnLocation, FireRotation);

		}
		World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveJugador::ShotTimerExpired, FireRate);

		bCanFire = false;

	}
}


void ANaveJugador::ShotTimerExpired()
{
	bCanFire = true;
}

void ANaveJugador::TakeItem(ACapsula* InventoryItem)
{
	InventoryItem->PickUp();
	ShipInventory->AddToInventory(InventoryItem);
}

void ANaveJugador::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	ACapsula* CapsulaItem = Cast<ACapsula>(Other);
	if (CapsulaItem != nullptr)
	{
		FString Name = CapsulaItem->GetCapsulaName();

		for (auto& pair : Datos)
		{
			if (pair.Key == Name)
			{
				pair.Value = pair.Value + 20;

				if (Name == "Velocidad") {
					MoveSpeed += pair.Value;
				}
				break;

				/*if (Name == "Vidas") {
					pair.Value = GetMenosVida(pair.Value);
				}
				break;*/
			}

			/*if (pair.Key == Name)
			{
				pair.Value = pair.Value - 1;
				break;
			}*/
		}

		TakeItem(CapsulaItem);

	}
}

void ANaveJugador::Lista()
{
	for (auto& Elem : Datos) {
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s = %d"), *Elem.Key, Elem.Value));
	}
}
