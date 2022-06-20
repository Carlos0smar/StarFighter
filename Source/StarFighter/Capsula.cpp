// Fill out your copyright notice in the Description page of Project Settings.


#include "Capsula.h"
#include "RandomMovementComponent_BP.h"

ACapsula::ACapsula()
{

	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile'"));
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

	SetActorEnableCollision(true);	 

	MoveRandCap = CreateDefaultSubobject<URandomMovementComponent_BP>(TEXT("MoverRandCap"));



}


void ACapsula::BeginPlay()
{
	Super::BeginPlay();
}

void ACapsula::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACapsula::PickUp()
{
	SetActorTickEnabled(false);
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void ACapsula::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Generando la capsula %s"), *GetCapsulaName()));
}
 