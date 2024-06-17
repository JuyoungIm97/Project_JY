// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Utils/JY_Define.h"
#include "JY_Singleton.h"

template<typename TClass>
TClass* TJY_Singleton<TClass>::MakeInstance()
{
	if(Instance != nullptr)
	{
		return nullptr;
	}

	Instance = JY_NewObject<TClass>();
	Instance->AddToRoot();
	return Instance;
}

template<typename TClass>
void TJY_Singleton<TClass>::RemoveInstance()
{
	if(Instance == nullptr)
	{
		return;
	}

	if(Instance->IsValidLowLevel())
	{
		Instance->RemoveFromRoot();
		JY_DeleteObject(Instance);
	}

	Instance = nullptr;
}

template<typename TClass>
TClass* TJY_Singleton<TClass>::GetInstance()
{
	return Instance;
}

template<typename TClass>
bool TJY_Singleton<TClass>::HasInstance()
{
	return Instance != nullptr && !Instance->HasAnyFlags(RF_FinishDestroyed);
}