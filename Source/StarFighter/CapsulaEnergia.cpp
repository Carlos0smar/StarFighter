// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaEnergia.h"

ACapsulaEnergia::ACapsulaEnergia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile'"));
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

	CapsulaName = "Energia";

	SetCapsulaName("Energia");
}

void ACapsulaEnergia::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, TEXT("Genera Armamento"));
}
