// Fill out your copyright notice in the Description page of Project Settings.


#include "Capsula.h"
#include "RandomMovementComponent_BP.h"

ACapsula::ACapsula():Super()
{

	PrimaryActorTick.bCanEverTick = true;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile'"));
	if (MeshAsset.Object != nullptr)
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);

	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	SetActorEnableCollision(true);

	SetCapsulaName("Velocidad");


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
 