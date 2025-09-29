// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SmashCharacter.generated.h"

class USmashCharacterStateMachine;
UCLASS()
class SMASHUE_API ASmashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASmashCharacter();
	float GetOrientX() const;
	void SetOrientX(float newOrientX);
	void RotateMeshWithOrient() const;
	void CreateStateMachine();
	void InitStateMachine();
	void Move();
	void StartMoving(float speed);
	void StopMoving();

	void TickStateMachine(float DeltaTime) const;

protected:
	// Called when the game starts or when spawned

	
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	float OrientX = 1;
	UPROPERTY(BlueprintreadWrite)
	TObjectPtr<USmashCharacterStateMachine> StateMachine;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	private:
		float FCurrentSpeed = 0.f;
	bool bIsMoving = false;
};
