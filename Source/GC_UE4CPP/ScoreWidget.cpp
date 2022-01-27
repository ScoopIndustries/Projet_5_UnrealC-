// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"


void UScoreWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	GenerateRandom();

	GenerateButton->OnClicked.AddUniqueDynamic(this, &UScoreWidget::OnButtonTestClicked);
}

void UScoreWidget::GenerateRandom()
{
	int32 RandomNumber = FMath::RandRange(0, 100);

	RandomNumberLabel->SetText(FText::AsNumber(RandomNumber));
}

void UScoreWidget::OnButtonTestClicked()
{
	GenerateRandom();
}