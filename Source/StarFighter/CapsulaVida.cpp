// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaVida.h"

void ACapsulaVida::BeginPlay()
{
	Super::BeginPlay();
}

ACapsulaVida::ACapsulaVida()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile'"));
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

	SetCapsulaName("Vida");
	CapsulaName = "Vida";
}

void ACapsulaVida::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, TEXT("Genera vida"));
}
