// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <GC_UE4CPP/PlayerGameMode.h>
#include <GC_UE4CPP/PlayerGameState.h>
#include <Runtime/UMG/Public/Components/ProgressBar.h>
#include <Runtime/UMG/Public/Components/TextBlock.h>
#include "ScoreWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GC_UE4CPP_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()

public :
	UFUNCTION()
	void UpdateScoreWidget();

protected:
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class APlayerGameMode* PlayerGameMode;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class APlayerGameState* PlayerGameState;

	UPROPERTY(meta = (BindWidget))
		UProgressBar* ScoreBar;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* CurrentScoreLabel;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* MaxScoreLabel;

	/*void GenerateRandom();

	UPROPERTY( meta = (BindWidget))
		class UTextBlock* RandomNumberLabel;

	UPROPERTY( meta = (BindWidget))
		class UButton* GenerateButton;

	UFUNCTION()
		void OnButtonTestClicked();*/
};
