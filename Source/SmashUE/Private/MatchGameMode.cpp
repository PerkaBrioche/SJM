// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchGameMode.h"

#include "SmashCharacter.h"
#include "Arena/ArenaPlayerStart.h"
#include "Kismet/GameplayStatics.h"


void AMatchGameMode::BeginPlay()
{
	Super::BeginPlay();
	SpawnCharacter();
}

void AMatchGameMode::SpawnCharacter()
{
	for (auto sp : GetAllSpawnPoints())
	{
		// GET TYPE FROM EACH SPAWNPOINTS
		EAutoReceiveInput::Type InputType = sp->AutoReceiveInput;
		TSubclassOf<ASmashCharacter> character = GetSmashCharacterFromInputType(InputType);
		if (character == nullptr){continue;}

		ASmashCharacter* instantiateCharacter = GetWorld()->SpawnActorDeferred<ASmashCharacter>(character, sp->GetTransform());

		if (instantiateCharacter == nullptr){continue;}
		instantiateCharacter->AutoPossessPlayer = sp->AutoReceiveInput;
		instantiateCharacter->FinishSpawning(sp->GetTransform());
		smashCharactersInGame.Add(instantiateCharacter);
	}
}




TSubclassOf<ASmashCharacter> AMatchGameMode::GetSmashCharacterFromInputType(EAutoReceiveInput::Type InputType) const
{
	switch (InputType)
	{
		case EAutoReceiveInput::Player0:
			return smashCharacterP0;
			break;
		case EAutoReceiveInput::Player1:
			return smashCharacterP1;
			break;
		case EAutoReceiveInput::Player2:
			return smashCharacterP2;
			break;
		case EAutoReceiveInput::Player3:
			return smashCharacterP3;
			break;

		default:
			return nullptr;
	}
}


TArray<AArenaPlayerStart*> AMatchGameMode::GetAllSpawnPoints()
{
	TArray<AActor*> SpawnPoints;
	TArray<AArenaPlayerStart*> spawnPointsFounded;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AArenaPlayerStart::StaticClass(), SpawnPoints);
	for (AActor* SpawnPoint : SpawnPoints)
	{
		AArenaPlayerStart* spawnPlayerStart = Cast<AArenaPlayerStart>(SpawnPoint);
		if (spawnPlayerStart == nullptr){continue;}
		spawnPointsFounded.Add(spawnPlayerStart);
	}
	return spawnPointsFounded;
}
