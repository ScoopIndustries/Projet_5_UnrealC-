// Fill out your copyright notice in the Description page of Project Settings.


#include "WinMenuWidget.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void UWinMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	RestartButton->OnClicked.AddUniqueDynamic(this, &UWinMenuWidget::RestartGame);

	//UGameplayStatics::SetGamePaused(GetWorld(), true);

	UGameplayStatics::GetPlayerController(this, 0)->SetShowMouseCursor(true);
	UGameplayStatics::GetPlayerController(this, 0)->UnPossess();
}

void UWinMenuWidget::RestartGame()
{
	UGameplayStatics::OpenLevel(this, "Level");
}

/*
	FPlatformMisc::RequestExit(false);
*/