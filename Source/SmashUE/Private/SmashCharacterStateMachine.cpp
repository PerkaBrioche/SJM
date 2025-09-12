// Fill out your copyright notice in the Description page of Project Settings.


#include "SmashCharacterStateMachine.h"

#include "SmashCharacterState.h"
#include "SmashCharacterStateID.h"


USmashCharacterStateMachine::USmashCharacterStateMachine()
{
	
}

void USmashCharacterStateMachine::InitStateMachine(ASmashCharacter* InASmashCharacter)
{
	CurrentASmashCharacter = InASmashCharacter;
	// CALL FIRST FIND STATES BEFORE CALL INITSTATES
	FindStates();
	InitiStates();
	
}

ASmashCharacter* USmashCharacterStateMachine::GetCharacter() const
{
	return CurrentASmashCharacter;
}



void USmashCharacterStateMachine::FindStates()
{
	if (HasTryFindState)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "ALREADY FOUND STATES");

		return;
	}
	
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "found states");

	HasTryFindState = true;
	TArray<UActorComponent*> FoundComponents = CurrentASmashCharacter->K2_GetComponentsByClass(USmashCharacterState::StaticClass());
	for (auto fc : FoundComponents)
	{
		USmashCharacterState* State = Cast<USmashCharacterState>(fc);
		if (State == nullptr){continue;}
		if (State->GetStateID() == ECharacterStates::None){continue;}
		AllStates.Add(State);
	}
}

void USmashCharacterStateMachine::InitiStates()
{
	if (!HasTryFindState)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "TRY FIND STATES BEFORES INIT THEM !");
		return;
	}
	for (auto fc : AllStates)
	{
		fc->InitMachineState(this);
	}
}



