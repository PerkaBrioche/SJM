// Fill out your copyright notice in the Description page of Project Settings.


#include "SmashCharacterStateIdle.h"

#include "SmashCharacterStateID.h"


// Sets default values for this component's properties
USmashCharacterStateIdle::USmashCharacterStateIdle()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

ECharacterStates USmashCharacterStateIdle::GetStateID()
{
	return ECharacterStates::Idle;
}

void USmashCharacterStateIdle::StateEnter(ECharacterStates PreviousStateID)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "ENTER IDLE STATE");
	Super::StateEnter(PreviousStateID);
}

void USmashCharacterStateIdle::StateExit(ECharacterStates NewStateID)
{
	Super::StateExit(NewStateID);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "EXIT IDLE STATE");
}

void USmashCharacterStateIdle::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
}



// Called when the game starts
void USmashCharacterStateIdle::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USmashCharacterStateIdle::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

