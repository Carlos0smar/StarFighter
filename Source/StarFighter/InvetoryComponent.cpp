// Fill out your copyright notice in the Description page of Project Settings.


#include "InvetoryComponent.h"
#include "Capsula.h"

// Sets default values for this component's properties
UInvetoryComponent::UInvetoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInvetoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInvetoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 UInvetoryComponent::AddToInventory(ACapsula* ActorToAdd)
{
	return ContentEjemplar.Add(ActorToAdd);
}

