// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JY_Widget.h"
#include "JY_Widget_Main.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_JY_API UJY_Widget_Main : public UJY_Widget
{
	GENERATED_BODY()
public:
	virtual void InitWidget(bool _bActive) override;
private: 
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UScrollBox> CPP_ScrollBox = nullptr; //tobject로 되있는 포인터
};