// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"


void UScoreWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	PlayerGameMode = Cast<APlayerGameMode>(GetWorld()->GetAuthGameMode());
	PlayerGameState = Cast<APlayerGameState>(GetWorld()->GetGameState());

	if (PlayerGameMode == nullptr)
		return;
	if (PlayerGameState == nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("PlayerGameState = nullptr"));

	UpdateScoreWidget();
}

void UScoreWidget::UpdateScoreWidget()
{

	CurrentScoreLabel->SetText(FText::AsNumber(PlayerGameState->FoodCollected));
	MaxScoreLabel->SetText(FText::AsNumber(PlayerGameMode->GetMaxFoodConditionWin()));

	ScoreBar->SetPercent(PlayerGameState->FoodCollected / PlayerGameMode->GetMaxFoodConditionWin());


	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("Function Update Widget Load !!"));

	/*GameMode = Cast<GC_UE4CPPGameModeBase>(OtherActor);
	if (GameMode != null)
	{
		ScoreBar->SetPercent(GameMode->FoodCollected / GameMode->MaxFoodConditionWin)
	}

	ScoreLabel->SetText(FText::FromString("6 / 10"));

	GenerateRandom();

	GenerateButton->OnClicked.AddUniqueDynamic(this, &UScoreWidget::OnButtonTestClicked);*/
}

/*void UScoreWidget::GenerateRandom()
{
	int32 RandomNumber = FMath::RandRange(0, 100);

	RandomNumberLabel->SetText(FText::AsNumber(RandomNumber));
}

void UScoreWidget::OnButtonTestClicked()
{
	GenerateRandom();
}*/