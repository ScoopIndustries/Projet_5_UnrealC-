// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AI/AIBotCharacter.h"
#include "AnimationBot.generated.h"

/**
 * 
 */
UCLASS(transient, Blueprintable, hideCategories=AnimInstance, BlueprintType)
class GC_UE4CPP_API UAnimationBot : public UAnimInstance
{
	GENERATED_BODY()

public:
	UAnimationBot();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Generic")
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Generic")
		bool isCarry;
		
	
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
