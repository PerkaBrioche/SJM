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
	ChangeState(ECharacterStates::Idle);
}

void USmashCharacterStateMachine::Tick(float DeltaTime)
{
	if (CurrentState == nullptr){return;}
	CurrentState->StateTick(DeltaTime);
}


ASmashCharacter* USmashCharacterStateMachine::GetCharacter() const
{
	return CurrentASmashCharacter;
}

void USmashCharacterStateMachine::ChangeState(ECharacterStates NewStateID)
{
	USmashCharacterState* NextState = GetState(NewStateID);
	if (NextState == nullptr){return;}

	if (CurrentState != nullptr)
	{
		CurrentState->StateExit(NewStateID);
	}

	ECharacterStates PreviousStateID = CurrentStateID;
	CurrentStateID = NewStateID;
	CurrentState = NextState;

	if (CurrentState == nullptr){return;}
	CurrentState->StateEnter(PreviousStateID);
}

USmashCharacterState* USmashCharacterStateMachine::GetState(ECharacterStates StateID)
{
	for (auto State : AllStates)
	{
		if (StateID == State->GetStateID())
		{
			return State;
		}
	}
	return nullptr;
}


void USmashCharacterStateMachine::FindStates()
{
	if (HasTryFindState)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "ALREADY FOUND STATES");

		return;
	}
	

	HasTryFindState = true;
	TArray<UActorComponent*> FoundComponents = CurrentASmashCharacter->K2_GetComponentsByClass(USmashCharacterState::StaticClass());
	for (auto fc : FoundComponents)
	{
		USmashCharacterState* State = Cast<USmashCharacterState>(fc);
		if (State == nullptr){continue;}
		if (State->GetStateID() == ECharacterStates::None){continue;}
		AllStates.Add(State);
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, State->GetName());
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



