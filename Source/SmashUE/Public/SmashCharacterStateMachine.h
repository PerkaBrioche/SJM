// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SmashCharacter.h"
#include "SmashCharacterStateID.h"
#include "UObject/Object.h"
#include "SmashCharacterStateMachine.generated.h"

class USmashCharacterState;

UCLASS()
class SMASHUE_API USmashCharacterStateMachine : public UObject
{
	GENERATED_BODY()

	USmashCharacterStateMachine();
public:
	void InitStateMachine(ASmashCharacter* InASmashCharacter);
	ASmashCharacter* GetCharacter() const;
	ECharacterStates GetStateID() const;
protected:
	UPROPERTY()
	ASmashCharacter* CurrentASmashCharacter;

	TArray<USmashCharacterState*> AllStates;

	void FindStates();
	void InitiStates();

private:
	bool HasTryFindState = false;
};
