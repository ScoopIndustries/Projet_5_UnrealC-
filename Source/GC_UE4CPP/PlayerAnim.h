// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerCharacter.h"
#include "PlayerAnim.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UPlayerAnim : public UAnimInstance
{
	GENERATED_BODY()
public:
	UPlayerAnim();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Generic")
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Generic")
		bool isCarry;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
