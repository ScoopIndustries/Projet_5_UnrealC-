// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameMode.h"
#include "ScoreWidget.h"
#include "Blueprint\UserWidget.h"

void APlayerGameMode::BeginPlay()
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
