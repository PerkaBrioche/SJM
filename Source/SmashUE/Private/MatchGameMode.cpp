// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchGameMode.h"

#include "Arena/ArenaPlayerStart.h"
#include "Kismet/GameplayStatics.h"


void AMatchGameMode::BeginPlay()
{
	Super::BeginPlay();
	TArray<AArenaPlayerStart*> spawnPoints;
	GetAllSpawnPoints(spawnPoints);



	for (auto sp : spawnPoints)
	{
		if (sp != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, sp->GetName());
		}
	}
}

void AMatchGameMode::GetAllSpawnPoints(TArray<AArenaPlayerStart*>& FoundActors)
{
	TArray<AActor*> SpawnPoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AArenaPlayerStart::StaticClass(), SpawnPoints);
	for (AActor* SpawnPoint : SpawnPoints)
	{
		AArenaPlayerStart* spawnPlayerStart = Cast<AArenaPlayerStart>(SpawnPoint);
		if (spawnPlayerStart == nullptr){continue;}
		FoundActors.Add(spawnPlayerStart);
	}
}
