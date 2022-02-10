// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Runtime/UMG/Public/Components/TextBlock.h>
#include <Runtime/UMG/Public/Components/Button.h>
#include "LoseMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API ULoseMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* LoseLabel;

	UPROPERTY(meta = (BindWidget))
		class UButton* RestartButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* QuitButton;

	UFUNCTION()
		void RestartGame();

	UFUNCTION()
		void QuitGame();
};
