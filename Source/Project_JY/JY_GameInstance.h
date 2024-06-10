// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "JY_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_JY_API UJY_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	
};
