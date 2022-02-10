// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "PlayerGameMode.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UGameplayStatics::GetPlayerController(this, 0)->SetShowMouseCursor(true);
	UGameplayStatics::SetGamePaused(GetWorld(), true);

	PlayButton->OnClicked.AddUniqueDynamic(this, &UMainMenuWidget::StartGame);
	QuitButton->OnClicked.AddUniqueDynamic(this, &UMainMenuWidget::QuitGame);

}

void UMainMenuWidget::StartGame()
{
	PlayerGameMode = Cast<APlayerGameMode>(GetWorld()->GetAuthGameMode());

	if (PlayerGameMode != nullptr)
	{
		PlayerGameMode->StartGame();
	}
}

void UMainMenuWidget::QuitGame()
{
	FPlatformMisc::RequestExit(false);
}