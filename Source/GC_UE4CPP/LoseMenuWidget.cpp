// Fill out your copyright notice in the Description page of Project Settings.


#include "LoseMenuWidget.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void ULoseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	RestartButton->OnClicked.AddUniqueDynamic(this, &ULoseMenuWidget::RestartGame);
}

void ULoseMenuWidget::RestartGame()
{
	UGameplayStatics::OpenLevel(this, "LevelFlo");
}