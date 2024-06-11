// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JY_Widget.h"
#include "JY_Widget_SelectMenu.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_JY_API UJY_Widget_SelectMenu : public UJY_Widget
{
	GENERATED_BODY()

protected:
	virtual void InitWidget() override;
	virtual void SynchronizeProperties() override;
	
private:
	void InitBG(TObjectPtr<UTexture2D> BGImage);
	void InitText(FString _Text);

	UPROPERTY(Category = "Practice", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FString Text;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UCanvasPanel> CPP_BGPanel = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> CPP_BGImage = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> CPP_SelectText = nullptr;
};
