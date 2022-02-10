// Fill out your copyright notice in the Description page of Project Settings.


#include "LoseMenuWidget.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void ULoseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UGameplayStatics::GetPlayerController(this, 0)->SetShowMouseCursor(true);
	UGameplayStatics::GetPlayerController(this, 0)->UnPossess();

	RestartButton->OnClicked.AddUniqueDynamic(this, &ULoseMenuWidget::RestartGame);
	QuitButton->OnClicked.AddUniqueDynamic(this, &ULoseMenuWidget::QuitGame);

}

void ULoseMenuWidget::RestartGame()
{
	UGameplayStatics::OpenLevel(this, "Level");
}

void ULoseMenuWidget::QuitGame()
{
	FPlatformMisc::RequestExit(false);
}