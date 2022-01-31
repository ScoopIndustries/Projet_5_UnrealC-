// Copyright Epic Games, Inc. All Rights Reserved.


#include "GC_UE4CPPGameModeBase.h"

#include "ScoreWidget.h"
#include "Blueprint\UserWidget.h"

void AGC_UE4CPPGameModeBase::BeginPlay()
{
	if (IsValid(WidgetClass))
	{
		ScoreWidget = Cast<UScoreWidget>(CreateWidget(GetWorld(), WidgetClass));

		if (ScoreWidget != nullptr)
		{
			ScoreWidget->AddToViewport();
		}
	}

}
