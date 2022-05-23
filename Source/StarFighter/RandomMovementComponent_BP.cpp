// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomMovementComponent_BP.h"

// Sets default values for this component's properties
URandomMovementComponent_BP::URandomMovementComponent_BP()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MovementRadius = 3;

	// ...
}


// Called when the game starts
void URandomMovementComponent_BP::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URandomMovementComponent_BP::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Parent = GetOwner();
	if (Parent)
	{
		Parent->SetActorLocation(Parent->GetActorLocation() + FVector(-1.0f, FMath::FRandRange(-5, 5) * MovementRadius, 0.0f));
	}

	// ...
}

