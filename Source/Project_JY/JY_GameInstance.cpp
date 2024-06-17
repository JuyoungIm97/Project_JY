// Fill out your copyright notice in the Description page of Project Settings.


#include "JY_GameInstance.h"

#include "Engine/LevelStreamingDynamic.h"
#include "Kismet/GameplayStatics.h"
#include "Manager/JY_SingletonManager.h"
#include "Manager/JY_WidgetManager.h"
#include "Widget/JY_Button_MainMenu.h"

UJY_GameInstance::UJY_GameInstance()
{
	FWorldDelegates::OnStartGameInstance.AddUObject(this, &UJY_GameInstance::OnStartGameInstance);
}

UJY_GameInstance::~UJY_GameInstance()
{
	FWorldDelegates::OnStartGameInstance.RemoveAll(this);
}

void UJY_GameInstance::Init()
{
	Super::Init();

	// 싱글턴 생성
	CreateSingleton();

	// 틱 생성
	TickDelegateHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UJY_GameInstance::Tick));
	// 레벨 로드
	LoadBaseWorld();
}

void UJY_GameInstance::Shutdown()
{
	Super::Shutdown();

	DestroyManagers();
}

bool UJY_GameInstance::Tick(float DeltaSeconds)
{
	if (UJY_SingletonManager::GetInstance())
	{
		UJY_SingletonManager::GetInstance()->TickSingletons(DeltaSeconds);
	}

	if(bLevelLoadSuccess)
	{
		StartGame();
	}
	
	return true;
}

void UJY_GameInstance::OnStartGameInstance(UGameInstance* GameInstance)
{
	if (UJY_SingletonManager* SingletonManager = UJY_SingletonManager::GetInstance())
	{
		SingletonManager->InitializeSingletons();
	}
}

void UJY_GameInstance::CreateSingleton()
{
	if(UJY_SingletonManager* SingletonManager = UJY_SingletonManager::CreateInstance())
	{
		SingletonManager->Initialize(this);
	}
}

void UJY_GameInstance::LoadBaseWorld()
{
	if(BaseWorld.IsValid())
	{
		const TObjectPtr<UWorld> World = UJY_SingletonManager::GetGameWorld();
		if(IsValid(World) == false)
		{
			return;
		}
		
		ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(World, BaseWorld, FVector::ZeroVector, FRotator::ZeroRotator, bLevelLoadSuccess);
	}
}

void UJY_GameInstance::DestroyManagers()
{
	if (UJY_SingletonManager* SingletonManager = UJY_SingletonManager::GetInstance())
	{
		SingletonManager->FinalizeSingletons();
	}

	UJY_SingletonManager::DestroyInstance();
	
}

void UJY_GameInstance::StartGame()
{
	gWidgetMng.Create_Widget(UJY_Widget_MainMenu::GetWidgetPath());
}
