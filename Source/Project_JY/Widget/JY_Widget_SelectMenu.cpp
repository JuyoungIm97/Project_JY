// Fill out your copyright notice in the Description page of Project Settings.


#include "JY_Widget_SelectMenu.h"

#include "Components/TextBlock.h"

void UJY_Widget_SelectMenu::InitWidget()
{
	Super::InitWidget();

	InitBG(nullptr);
	InitText(FString());
}

void UJY_Widget_SelectMenu::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if(Text.Len() != 0)
	{
		CPP_SelectText->SetText(FText::FromString(Text));
	}
}

void UJY_Widget_SelectMenu::InitBG(TObjectPtr<UTexture2D> BGImage)
{
}

void UJY_Widget_SelectMenu::InitText(FString _Text)
{
	CPP_SelectText->SetText(FText::FromString(_Text));
}
