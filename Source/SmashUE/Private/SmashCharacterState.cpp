// Fill out your copyright notice in the Description page of Project Settings.


#include "SmashCharacterState.h"

#include "SmashCharacterStateID.h"
#include "SmashCharacterStateMachine.h"


USmashCharacterState::USmashCharacterState()
{
	PrimaryComponentTick.bCanEverTick = false;
}

ECharacterStates USmashCharacterState::GetStateID()
{
	return ECharacterStates::None;
}


void USmashCharacterState::InitMachineState(USmashCharacterStateMachine* InSm)
{
	StateMachine = InSm;
	Character = InSm->GetCharacter();
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, FString::Printf(TEXT("%hhd"), InSm->GetStateID()));
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, FString::Printf(TEXT("%s"), InSm->GetStateID()));
}



