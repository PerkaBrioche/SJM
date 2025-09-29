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
	CreateStateMachine();
	InitStateMachine();
	Super::BeginPlay();
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

void ASmashCharacter::Move()
{
	FVector position = GetTransform().GetLocation();
	// MULTIPLY VECTOR

	position *= FCurrentSpeed * GetWorld()->GetDeltaSeconds() * OrientX;
	AddMovementInput(position);
	
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("FORWARD VECTOR: %s"), *position.ToString()));
}

void ASmashCharacter::StartMoving(float speed)
{
	FCurrentSpeed = speed;
	bIsMoving = true;
}

void ASmashCharacter::StopMoving()
{
	FCurrentSpeed = 0.f;
	bIsMoving = false;
}

void ASmashCharacter::TickStateMachine(float DeltaTime) const
{
	if (StateMachine == nullptr){return;}
	StateMachine->Tick(DeltaTime);
}


// Called every frame
void ASmashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TickStateMachine(DeltaTime);
	RotateMeshWithOrient();
	
	if (!bIsMoving ){return;}
	Move();
}

// Called to bind functionality to input
void ASmashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}



