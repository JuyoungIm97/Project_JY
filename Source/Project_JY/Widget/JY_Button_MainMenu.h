// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JY_Widget.h"
#include "JY_Button_MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_JY_API UJY_Widget_MainMenu : public UJY_Widget
{
	GENERATED_BODY()
public:
	static FORCEINLINE FSoftObjectPath GetWidgetPath() { return FSoftObjectPath(TEXT("/Game/UI/Widget/Main_Widget.Main_Widget")); } 
	
	virtual void InitWidget(bool _bActive) override;
protected:
	virtual void SynchronizeProperties() override;
	
private:
	void InitBG(TObjectPtr<class UTexture2D> BGImage);
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
