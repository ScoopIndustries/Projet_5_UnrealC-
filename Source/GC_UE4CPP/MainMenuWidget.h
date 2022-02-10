// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Runtime/UMG/Public/Components/TextBlock.h>
#include <Runtime/UMG/Public/Components/Button.h>
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	void NativeConstruct() override;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class APlayerGameMode* PlayerGameMode;

	UPROPERTY(meta = (BindWidget))
		class UButton* PlayButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* QuitButton;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* TitleLabel;
	
	UFUNCTION()
		void StartGame();

	UFUNCTION()
		void QuitGame();
};
