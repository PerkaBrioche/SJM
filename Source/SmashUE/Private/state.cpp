// Fill out your copyright notice in the Description page of Project Settings.


#include "state.h"

#include "SmashCharacter.h"


// Sets default values for this component's properties
USCS_Walk::USCS_Walk()
{

	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void USCS_Walk::BeginPlay()
{
	Super::BeginPlay();
}

ECharacterStates USCS_Walk::GetStateID()
{
	return ECharacterStates::Walk;
}

void USCS_Walk::StateTick(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "TICK STATE WALK");
	
}

void USCS_Walk::StateEnter(ECharacterStates PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	if (Character == nullptr){return;}
	Character->StartMoving(WalkSpeed);
}

void USCS_Walk::StateExit(ECharacterStates NewStateID)
{
	Super::StateExit(NewStateID);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "EXIT WALK STATE");
	if (Character == nullptr){return;}
	Character->StopMoving();
}

// Called every frame
void USCS_Walk::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

