// Fill out your copyright notice in the Description page of Project Settings.


#include "Capsula.h"
#include "Components/BoxComponent.h"
#include "SpawnCapsula.h"
// Sets default values
ASpawnCapsula::ASpawnCapsula()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;

}

ACapsula* ASpawnCapsula::GetCapsula(FString TipoCapsula)
{
	ACapsula* capsula = FabricarCapsula(TipoCapsula);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("Fabricando capsula %s"), *capsula->GetCapsulaName()));
	capsula->Generar();
	return capsula;
}
// Called when the game starts or when spawned
void ASpawnCapsula::BeginPlay()
{
	Super::BeginPlay();
	//const FVector Location = FVector(200.f, 0.f, 0.f);
	//const FRotator Rotation = FRotator(0.f, 0.f, 180.f);


/*	FVector Location = WhereToSpawn->GetComponentLocation();
	float Y = WhereToSpawn->GetScaledBoxExtent().Y;
	Location.Y = FMath::RandRange(Location.Y - Y, Location.Y + Y);
	UE_LOG(LogTemp, Warning, TEXT("Should Spawn at: %s"), *Location.ToString());
	FRotator Rotation = GetActorRotation();
	Rotation.Yaw = 180.0f;*/



	//GetWorld()->SpawnActor<ACapsula>(ACapsula::StaticClass(), Location, Rotation);
	
}

// Called every frame
void ASpawnCapsula::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

