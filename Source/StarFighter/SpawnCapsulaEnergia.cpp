// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnCapsulaEnergia.h"
#include "Components/BoxComponent.h"
#include "Capsula.h"
#include "SpawnCapsula.h"
#include "CapsulaEnergia.h"

ASpawnCapsulaEnergia::ASpawnCapsulaEnergia()
{
	//PrimaryActorTick.bCanEverTick = true;
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;
}

void ASpawnCapsulaEnergia::BeginPlay()
{
	Super::BeginPlay();
}


void ASpawnCapsulaEnergia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ACapsula* ASpawnCapsulaEnergia::FabricarCapsula(FString NombreTipoCapsula)
{
	FVector Location = WhereToSpawn->GetComponentLocation();
	float Y = WhereToSpawn->GetScaledBoxExtent().Y;
	Location.Y = FMath::RandRange(Location.Y - Y, Location.Y + Y);
	UE_LOG(LogTemp, Warning, TEXT("Should Spawn at: %s"), *Location.ToString());
	FRotator Rotation = GetActorRotation();
	Rotation.Yaw = 180.0f;
	GetWorld()->SpawnActor<ACapsulaEnergia>(ACapsulaEnergia::StaticClass(), Location, Rotation);

	return nullptr;
}



