// Fill out your copyright notice in the Description page of Project Settings.


#include "JY_WidgetManager.h"

#include "JY_SingletonManager.h"
#include "Utils/JY_Utility.h"
#include "Widget/JY_Widget.h"

UJY_WidgetManager::UJY_WidgetManager()
{
}

UJY_WidgetManager::~UJY_WidgetManager()
{
}

void UJY_WidgetManager::BuiltInInitialize()
{
	TJY_Singleton<UJY_WidgetManager>::BuiltInInitialize();
}

void UJY_WidgetManager::Initialize()
{
	TJY_Singleton<UJY_WidgetManager>::Initialize();
}

void UJY_WidgetManager::Finalize()
{
	TJY_Singleton<UJY_WidgetManager>::Finalize();
}

void UJY_WidgetManager::BuiltInFinalize()
{
	TJY_Singleton<UJY_WidgetManager>::BuiltInFinalize();
}

void UJY_WidgetManager::Tick(float DeltaTime)
{
	TJY_Singleton<UJY_WidgetManager>::Tick(DeltaTime);
}

TObjectPtr<UJY_Widget> UJY_WidgetManager::Create_Widget(const FSoftObjectPath& WidgetPath)
{
	GEngine->ForceGarbageCollection(true);
	
	const TObjectPtr<UJY_Widget> Widget = CreateWidget_Internal(WidgetPath.ToString());
	JY_CHECK(Widget);

	if(Widget)
	{
		Widget->InitWidget(true);
	}

	return Widget;
}

TObjectPtr<UJY_Widget> UJY_WidgetManager::CreateWidget_Internal(const FString& WidgetPath) const
{
	static FString SubName = TEXT("Create Widget");
	const FString ClassName = WidgetPath + TEXT("_C");
	
	const TObjectPtr<UClass> WidgetClass = Cast<UClass>(JY_Utility::LoadObjectFromFile(ClassName));
	const TObjectPtr<UWorld> World = UJY_SingletonManager::GetGameWorld();
	
	if(World == nullptr)// && World->bIsTearingDown == false)
	{
		return nullptr;
	}

	const TObjectPtr<UJY_Widget> _Widget = CreateWidget<UJY_Widget>(World, WidgetClass);
	if(_Widget == nullptr)
	{
		return nullptr;
	}
	
	return _Widget;
}
