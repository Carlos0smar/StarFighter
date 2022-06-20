// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnCapsulaArmamento.h"
#include "Capsula.h"
#include "SpawnCapsula.h"
#include "Components/BoxComponent.h"
#include "CapsulaArmamento.h"

ASpawnCapsulaArmamento::ASpawnCapsulaArmamento()
{
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;
}

void ASpawnCapsulaArmamento::BeginPlay()
{
	Super::BeginPlay();
}


void ASpawnCapsulaArmamento::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ACapsula* ASpawnCapsulaArmamento::FabricarCapsula(FString NombreTipoCapsula)
{
	FVector Location = WhereToSpawn->GetComponentLocation();
	float Y = WhereToSpawn->GetScaledBoxExtent().Y;
	Location.Y = FMath::RandRange(Location.Y - Y, Location.Y + Y);
	UE_LOG(LogTemp, Warning, TEXT("Should Spawn at: %s"), *Location.ToString());
	FRotator Rotation = GetActorRotation();
	Rotation.Yaw = 180.0f;
	GetWorld()->SpawnActor<ACapsulaArmamento>(ACapsulaArmamento::StaticClass(), Location, Rotation);

	return nullptr;
}


