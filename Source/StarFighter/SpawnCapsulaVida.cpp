// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnCapsulaVida.h"
#include "CapsulaVida.h"
#include "Capsula.h"
#include "Components/BoxComponent.h"
#include "SpawnCapsula.h"


void ASpawnCapsulaVida::BeginPlay()
{
    Super::BeginPlay();
}

void ASpawnCapsulaVida::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

ACapsula* ASpawnCapsulaVida::FabricarCapsula(FString NombreTipoCapsula)
{

  //  GetWorld()->SpawnActor<ACapsulaVida>(ACapsulaVida::StaticClass());
	FVector Location = WhereToSpawn->GetComponentLocation();
	float Y = WhereToSpawn->GetScaledBoxExtent().Y;
	Location.Y = FMath::RandRange(Location.Y - Y, Location.Y + Y);
	UE_LOG(LogTemp, Warning, TEXT("Should Spawn at: %s"), *Location.ToString());
	FRotator Rotation = GetActorRotation();
	Rotation.Yaw = 180.0f;

    GetWorld()->SpawnActor<ACapsulaVida>(ACapsulaVida::StaticClass(), Location, Rotation);

    return nullptr;
}

ASpawnCapsulaVida::ASpawnCapsulaVida()
{
	//PrimaryActorTick.bCanEverTick = true;
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;
}
