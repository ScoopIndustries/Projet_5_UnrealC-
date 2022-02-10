// Copyright Epic Games, Inc. All Rights Reserved.


#include "GC_UE4CPPGameModeBase.h"
#include "ScoreWidget.h"
#include "Blueprint\UserWidget.h"
#include "AI/Waypoint.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

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
