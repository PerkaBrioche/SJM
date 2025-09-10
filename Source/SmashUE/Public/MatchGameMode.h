// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MatchGameMode.generated.h"

class AArenaPlayerStart; // WHY NOT #INCLUDE ?
class ASmashCharacter;
/**
 * 
 */

UCLASS()
class SMASHUE_API AMatchGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
private:
	TArray<AArenaPlayerStart*> GetAllSpawnPoints();
	TSubclassOf<ASmashCharacter> GetSmashCharacterFromInputType(EAutoReceiveInput::Type InputType) const;
	void SpawnCharacter();
protected:
	UPROPERTY()
	TArray<ASmashCharacter*> smashCharactersInGame;

};
