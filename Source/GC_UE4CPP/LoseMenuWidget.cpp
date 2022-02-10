// Fill out your copyright notice in the Description page of Project Settings.


#include "LoseMenuWidget.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void ULoseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	RestartButton->OnClicked.AddUniqueDynamic(this, &ULoseMenuWidget::RestartGame);
	UGameplayStatics::GetPlayerController(this, 0)->SetShowMouseCursor(true);

}

void ULoseMenuWidget::RestartGame()
{
	UGameplayStatics::GetPlayerController(this, 0)->SetShowMouseCursor(false);
	UGameplayStatics::OpenLevel(this, "LevelFlo");
}