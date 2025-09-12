// Fill out your copyright notice in the Description page of Project Settings.


#include "SmashCharacter.h"

#include "SmashCharacterStateMachine.h"


// Sets default values
ASmashCharacter::ASmashCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASmashCharacter::BeginPlay()
{
	Super::BeginPlay();
	CreateStateMachine();
	InitStateMachine();
}

float ASmashCharacter::GetOrientX() const
{
	return OrientX;
}

void ASmashCharacter::SetOrientX(float newOrientX)
{
	OrientX = newOrientX;
}

void ASmashCharacter::RotateMeshWithOrient() const
{
	FRotator actualRotation = GetMesh()->GetRelativeRotation();
	actualRotation.Yaw = - 90.f * OrientX;
	GetMesh()->SetRelativeRotation(actualRotation);
}

void ASmashCharacter::CreateStateMachine()
{
	StateMachine = NewObject<USmashCharacterStateMachine>(this);
}

void ASmashCharacter::InitStateMachine()
{
	if (StateMachine == nullptr){return;}
	StateMachine->InitStateMachine(this);
}


// Called every frame
void ASmashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASmashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

