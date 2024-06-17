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
	UJY_GameInstance();
	virtual ~UJY_GameInstance() override;
	virtual void Init() override;
	virtual void Shutdown() override;
	
	bool Tick(float DeltaSeconds);
private:
	void OnStartGameInstance(UGameInstance* GameInstance);
	
	void CreateSingleton();
	void LoadBaseWorld();
	
	void DestroyManagers();
	
	void StartGame();

	UPROPERTY(Category = UJY_GameInstance, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSoftObjectPtr<UWorld> BaseWorld;

	FTSTicker::FDelegateHandle TickDelegateHandle;

	bool bLevelLoadSuccess = false;
};
