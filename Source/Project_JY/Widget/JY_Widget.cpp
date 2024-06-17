// Fill out your copyright notice in the Description page of Project Settings.


#include "JY_Widget.h"

#include "MovieScene.h"
#include "Animation/WidgetAnimation.h"

void UJY_Widget::InitWidget(bool _bActive)
{
	bool asdf = IsVisible();
	FillDefaultAnimations();
	
	AddToViewport(100);
	
	bool fdsa = IsVisible();
	if(IsVisible())
	{
		if(IsExistAnim(DefaultWidgetAnimation::Appearance) == true)
		{
			PlayAnimationByName(DefaultWidgetAnimation::Appearance);
		}

		if(_bActive == false)
		{
			SetVisibility(ESlateVisibility::Collapsed);
		}
	}
	bActive = _bActive;
}

void UJY_Widget::FillDefaultAnimations()
{
	Animations.Empty();

	FProperty* Property = GetClass()->PropertyLink;
	while(Property != nullptr)
	{
		if(Property->GetClass() == FObjectProperty::StaticClass())
		{
			if(const FObjectProperty* ObjectProperty = CastField<FObjectProperty>(Property))
			{
				if(ObjectProperty->PropertyClass == UWidgetAnimation::StaticClass())
				{
					TObjectPtr<UWidgetAnimation> WidgetAnimObject = Cast<UWidgetAnimation>(ObjectProperty->GetObjectPropertyValue_InContainer(this));

					if(WidgetAnimObject && WidgetAnimObject->MovieScene != nullptr)
					{
						Animations.Emplace(WidgetAnimObject->GetMovieScene()->GetName(), WidgetAnimObject);
					}
				}
			}
		}
		Property = Property->PropertyLinkNext;
	}
}

TObjectPtr<UWidgetAnimation> UJY_Widget::GetAnimationByName(FName AnimName) const
{
	TObjectPtr<UWidgetAnimation> const* pWidgetAnim = Animations.Find(AnimName);

	return pWidgetAnim == nullptr ? nullptr : *pWidgetAnim;
}

void UJY_Widget::PlayAnimationByName(FName Name, float StartTime, int32 LoopCount, EUMGSequencePlayMode::Type PlayType, float Speed)
{
	if(const TObjectPtr<UWidgetAnimation> WidgetAnimation = GetAnimationByName(Name))
	{
		PlayAnimation(WidgetAnimation, StartTime, LoopCount, PlayType, Speed);
	}
}

bool UJY_Widget::IsExistAnim(FName AnimName) const
{
	const TObjectPtr<UWidgetAnimation> WidgetAnim = GetAnimationByName(AnimName);

	return WidgetAnim != nullptr;
}
