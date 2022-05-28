// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnValue.h"
#include "EnemigoAereo1.h"
#include "Capsula.h"
#include "Components/BoxComponent.h"

// Sets default values
ASpawnValue::ASpawnValue()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;

}

// Called when the game starts or when spawned
void ASpawnValue::BeginPlay()
{
	Super::BeginPlay();

    SpawnClasses.Add(AEnemigoAereo1::StaticClass());
    UE_LOG(LogTemp, Warning, TEXT("Box: %s"), *WhereToSpawn->GetScaledBoxExtent().ToString());

    SpawnClasses.Add(ACapsula::StaticClass());
    UE_LOG(LogTemp, Warning, TEXT("Box: %s"), *WhereToSpawn->GetScaledBoxExtent().ToString());

	
}

// Called every frame
void ASpawnValue::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    const int Index = FMath::RandRange(0, SpawnClasses.Num() - 1);

    SpawnCoolDown += DeltaTime;
    if (SpawnCoolDown >= NextSpawnCoolDown)
    {
        FVector Location = WhereToSpawn->GetComponentLocation();
        float Y = WhereToSpawn->GetScaledBoxExtent().Y;
        Location.Y= FMath::RandRange(Location.Y - Y, Location.Y + Y);
        UE_LOG(LogTemp, Warning, TEXT("Should Spawn at: %s"), *Location.ToString());
        SpawnCoolDown = 0.0f;
        FRotator Rotation = GetActorRotation();
        Rotation.Yaw = 180.0f;
        GetWorld()->SpawnActor(SpawnClasses[Index], &Location, &Rotation);

    }
}

