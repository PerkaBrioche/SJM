// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SmashCharacterStateID.h"
#include "Components/ActorComponent.h"
#include "SmashCharacterState.generated.h"

class ASmashCharacter;
class USmashCharacterStateMachine;

UCLASS(Abstract)
class SMASHUE_API USmashCharacterState : public UActorComponent
{
	GENERATED_BODY()
public:
	USmashCharacterState();
	virtual ECharacterStates GetStateID();
	virtual void InitMachineState(USmashCharacterStateMachine* InSm);

	virtual void StateEnter(ECharacterStates PreviousStateID);
	virtual void StateExit(ECharacterStates NewStateID);

	virtual void StateTick(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	virtual UAnimMontage* GetAnimMontage();
	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimMontage> UAM_Animation;
	
protected:
	UPROPERTY()
	TObjectPtr<ASmashCharacter> Character;

	UPROPERTY()
	TObjectPtr<USmashCharacterStateMachine> StateMachine;

	private:
	ECharacterStates ActualStateCharacter;
};
