// Fill out your copyright notice in the Description page of Project Settings.


#include "SmashCharacter.h"


// Sets default values
ASmashCharacter::ASmashCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASmashCharacter::BeginPlay()
{
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

