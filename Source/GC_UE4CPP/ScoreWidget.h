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

protected :

	void GenerateRandom();

	UPROPERTY( meta = ( TestWidget ))
		class UTextBlock* RandomNumberLabel;

	UPROPERTY( meta = ( TestWidget ))
		class UButton* GenerateButton;

	UFUNCTION()
		void OnButtonTestClicked();
	
	void NativeConstruct() override;

};
