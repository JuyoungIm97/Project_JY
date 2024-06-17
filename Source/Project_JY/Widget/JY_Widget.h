// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "JY_Widget.generated.h"

namespace DefaultWidgetAnimation
{
	const FName Appearance = TEXT("Appearance");
	const FName DisAppearance = TEXT("DisAppearance");
	
	const FName Idle = TEXT("Idle");
}

/**
 * 
 */
UCLASS()
class PROJECT_JY_API UJY_Widget : public UUserWidget
{
	GENERATED_BODY()
	

public:
	virtual void InitWidget(bool _bActive);
	
	void FillDefaultAnimations();
	
	TObjectPtr<UWidgetAnimation> GetAnimationByName(FName AnimName) const;
protected:
	void PlayAnimationByName(FName Name, float StartTime = 0.f, int32 LoopCount = 1, EUMGSequencePlayMode::Type PlayType = EUMGSequencePlayMode::Forward, float Speed = 1.f);

	
	bool bActive;
	
	UPROPERTY()
	TMap<FName, TObjectPtr<UWidgetAnimation>> Animations;

private:
	bool IsExistAnim(FName AnimName) const;
};
