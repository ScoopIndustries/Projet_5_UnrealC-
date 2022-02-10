// Fill out your copyright notice in the Description page of Project Settings.


#include "WinMenuWidget.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void UWinMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UGameplayStatics::GetPlayerController(this, 0)->SetShowMouseCursor(true);
	UGameplayStatics::GetPlayerController(this, 0)->UnPossess();

	RestartButton->OnClicked.AddUniqueDynamic(this, &UWinMenuWidget::RestartGame);
	QuitButton->OnClicked.AddUniqueDynamic(this, &UWinMenuWidget::QuitGame);
}

void UWinMenuWidget::RestartGame()
{
	UGameplayStatics::OpenLevel(this, "Level");
}

void UWinMenuWidget::QuitGame()
{
	FPlatformMisc::RequestExit(false);
}