// Fill out your copyright notice in the Description page of Project Settings.


#include "JY_SingletonManager.h"

#include "JY_GameInstance.h"
#include "JY_Singleton.h"
#include "JY_WidgetManager.h"
#include "Project_JY/Utils/JY_Define.h"

UJY_SingletonManager* UJY_SingletonManager::Instance = nullptr;

void UJY_SingletonManager::Initialize(UJY_GameInstance* _GameInstance)
{
	GameInstance = _GameInstance;
}

UJY_SingletonManager* UJY_SingletonManager::CreateInstance()
{
	Instance = JY_NewObject<UJY_SingletonManager>();
	Instance->AddToRoot();
	Instance->RegisterSingletons();
	Instance->RegisterSingletonsForTick();
	return Instance;
}

void UJY_SingletonManager::DestroyInstance()
{
	if (Instance != nullptr)
	{
		Instance->RemoveSingletons();
		Instance->RemoveFromRoot();
		JY_DeleteObject(Instance);
		Instance = nullptr;
	}
}

TObjectPtr<UWorld> UJY_SingletonManager::GetGameWorld()
{
	return Instance ? Instance->GameInstance ? Instance->GameInstance->GetWorld() : nullptr : nullptr;
}

void UJY_SingletonManager::BuiltInInitializeSingletons()
{
	for (ISingleton* Singleton : Singletons)
	{
		Singleton->BuiltInInitialize();
	}

	bIsBuiltInInitialized = true;
}

void UJY_SingletonManager::InitializeSingletons()
{
	if(bInitialized)
	{
		return;
	}
    
	for (ISingleton* Singleton : Singletons)
	{
		Singleton->Initialize();
	}

	bInitialized = true;
}

void UJY_SingletonManager::FinalizeSingletons()
{
	if (bInitialized == false)
	{
		return;
	}

	for (ISingleton* Singleton : Singletons)
	{
		Singleton->PreFinalize();
		Singleton->Finalize();
		Singleton->BuiltInFinalize();
	}
}

void UJY_SingletonManager::TickSingletons(float DeltaTime)
{
	if (bInitialized)
	{
		for (ISingleton* Singleton : Singletons)
		{
			Singleton->Tick(DeltaTime);
		}
	}
}

void UJY_SingletonManager::RemoveSingletons()
{
	Singletons.Reset();
	SingletonsForTick.Reset();

	UJY_WidgetManager::RemoveInstance();
}

void UJY_SingletonManager::RegisterSingletons()
{
	Singletons.Reset();
	
	Singletons.Emplace(UJY_WidgetManager::MakeInstance());
}

void UJY_SingletonManager::RegisterSingletonsForTick()
{
	SingletonsForTick.Reset();
	
	SingletonsForTick.Emplace(UJY_WidgetManager::MakeInstance());
}
