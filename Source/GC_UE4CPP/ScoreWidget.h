// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
		class UProgressBar* Score;

	/*void GenerateRandom();

	UPROPERTY( meta = (BindWidget))
		class UTextBlock* RandomNumberLabel;

	UPROPERTY( meta = (BindWidget))
		class UButton* GenerateButton;

	UFUNCTION()
		void OnButtonTestClicked();*/
};
