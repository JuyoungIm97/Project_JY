// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JY_Singleton.h"
#include "Engine/StreamableManager.h"
#include "UObject/Object.h"
#include "JY_WidgetManager.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_JY_API UJY_WidgetManager : public UObject, public TJY_Singleton<UJY_WidgetManager>
{
	GENERATED_BODY()
	
public:
	UJY_WidgetManager();
	virtual ~UJY_WidgetManager() override;
	
	virtual void BuiltInInitialize() override;
	virtual void Initialize() override;
	virtual void Finalize() override;
	virtual void BuiltInFinalize() override;
	virtual void Tick(float DeltaTime) override;
	
	TObjectPtr<class UJY_Widget> Create_Widget(const FSoftObjectPath& WidgetPath);
	
	FORCEINLINE FStreamableManager& GetAssetLoader() { return AssetLoader; }

private:
	TObjectPtr<UJY_Widget> CreateWidget_Internal(const FString& WidgetPath) const;
	
	FStreamableManager AssetLoader;
	
#define gWidgetMng (*UJY_WidgetManager::GetInstance())
};
