﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SmashCharacter.h"
#include "Engine/DeveloperSettings.h"
#include "ArenaSettings.generated.h"


UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Smash Arena Settings"))
class SMASHUE_API UArenaSettings : public UDeveloperSettings
{
	GENERATED_BODY()

	public:
	UPROPERTY(config, EditAnywhere, Category = "Characters")
	TSubclassOf<ASmashCharacter> smashCharacterClass0;
	UPROPERTY(config, EditAnywhere, Category = "Characters")
	TSubclassOf<ASmashCharacter> smashCharacterClass1;
	UPROPERTY(config, EditAnywhere, Category = "Characters")
	TSubclassOf<ASmashCharacter> smashCharacterClass2;
	UPROPERTY(config, EditAnywhere, Category = "Characters")
	TSubclassOf<ASmashCharacter> smashCharacterClass3;
};
