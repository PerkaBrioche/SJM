// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SmashCharacterState.h"
#include "state.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SMASHUE_API USCS_Walk : public USmashCharacterState
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USCS_Walk();

	UPROPERTY(EditAnywhere)
	float WalkSpeed;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual ECharacterStates GetStateID() override;

	virtual void StateEnter(ECharacterStates PreviousStateID) override;
	virtual void StateExit(ECharacterStates NewStateID) override;

	virtual void StateTick(float DeltaTime) override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
