// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "JY_SingletonManager.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_JY_API UJY_SingletonManager : public UObject
{
	GENERATED_BODY()
public:
	UJY_SingletonManager() {}
	virtual ~UJY_SingletonManager() override {}
	void Initialize(class UJY_GameInstance* _GameInstance);

	static UJY_SingletonManager* CreateInstance();
	static void DestroyInstance();
	static UJY_SingletonManager* GetInstance() { return Instance; }

	static TObjectPtr<UWorld> GetGameWorld();
	void BuiltInInitializeSingletons();

	void InitializeSingletons();
	void FinalizeSingletons();
	
	void TickSingletons(float DeltaTime);

	void RemoveSingletons();

protected:
	static UJY_SingletonManager* Instance;

private:
	void RegisterSingletons();
	void RegisterSingletonsForTick();
	
	bool bIsBuiltInInitialized = false;
	bool bInitialized = false;
	
	UPROPERTY()
	TObjectPtr<class UJY_GameInstance> GameInstance = nullptr;
	
	TArray<class ISingleton*> Singletons;
	TArray<class ISingleton*> SingletonsForTick;
};
