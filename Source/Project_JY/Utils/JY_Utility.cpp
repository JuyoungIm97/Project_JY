// Fill out your copyright notice in the Description page of Project Settings.


#include "JY_Utility.h"
#include "Manager/JY_WidgetManager.h"
#include "UObject/ObjectPtr.h"

TObjectPtr<UObject> JY_Utility::LoadObjectFromFile(const FString& ResourcePath)
{
	const FSoftObjectPath Reference = ResourcePath;

	if(gWidgetMng.HasInstance() == false)
	{
		return nullptr;
	}
	
	UObject* ResultObject = gWidgetMng.GetAssetLoader().LoadSynchronous(Reference);
	
	return ResultObject;
}
