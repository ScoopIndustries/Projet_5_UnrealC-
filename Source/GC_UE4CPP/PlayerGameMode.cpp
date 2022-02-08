// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameMode.h"
#include "ScoreWidget.h"
#include "WinMenuWidget.h"
#include "LoseMenuWidget.h"
#include "Blueprint\UserWidget.h"

void APlayerGameMode::BeginPlay()
{
	if (IsValid(ScoreWidgetClass))
	{
		ScoreWidget = Cast<UScoreWidget>(CreateWidget(GetWorld(), ScoreWidgetClass));
		WinWidget = Cast<UWinMenuWidget>(CreateWidget(GetWorld(), WinWidgetClass));
		LoseWidget = Cast<ULoseMenuWidget>(CreateWidget(GetWorld(), LoseWidgetClass));

		if (ScoreWidget != nullptr)
		{
			ScoreWidget->AddToViewport();
		}
	}
}

void APlayerGameMode::GameWin()
{
	ScoreWidget->RemoveFromViewport();

	if (WinWidget != nullptr)
	{
		WinWidget->AddToViewport();
		
	}
}

void APlayerGameMode::GameLost()
{
	ScoreWidget->RemoveFromViewport();

	if (LoseWidget != nullptr)
	{
		LoseWidget->AddToViewport();
	}
}
