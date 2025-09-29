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

void USmashCharacterState::StateTick(float DeltaTime)
{
}

UAnimMontage* USmashCharacterState::GetAnimMontage()
{
	return UAM_Animation;
}

void USmashCharacterState::InitMachineState(USmashCharacterStateMachine* InSm)
{
	StateMachine = InSm;
	Character = InSm->GetCharacter();
}

void USmashCharacterState::StateEnter(ECharacterStates PreviousStateID)
{
	auto A = GetAnimMontage();
	Character->PlayAnimMontage(A);
}

void USmashCharacterState::StateExit(ECharacterStates NewStateID)
{
	
}



