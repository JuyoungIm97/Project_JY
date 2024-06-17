// Fill out your copyright notice in the Description page of Project Settings.


#include "JY_Button_MainMenu.h"

#include "Components/TextBlock.h"

void UJY_Widget_MainMenu::InitWidget(bool _bActive)
{
	Super::InitWidget(_bActive);

	InitBG(nullptr);
	InitText(FString());
}

void UJY_Widget_MainMenu::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if(Text.Len() != 0)
	{
		CPP_SelectText->SetText(FText::FromString(Text));
	}
}

void UJY_Widget_MainMenu::InitBG(TObjectPtr<UTexture2D> BGImage)
{
}

void UJY_Widget_MainMenu::InitText(FString _Text)
{
	CPP_SelectText->SetText(FText::FromString(_Text));
}
