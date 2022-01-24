// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Runtime/Engine/Classes/Camera/CameraComponent.h>
#include <Runtime/Engine/Classes/GameFramework/SpringArmComponent.h>
#include "PlayerCharacter.generated.h"

UCLASS()
class GC_UE4CPP_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	// Sets default values for this character's properties
	APlayerCharacter();

protected:

	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* CameraFollow;

	// fonction pour avancer / reculer
	void MoveForward(float Value);

	// fonction pour right / left
	void MoveRight(float Value);

	virtual void BeginPlay() override;

public:	

	UPROPERTY(VisibleAnywhere)
		float BaseTurnRate;

	UPROPERTY(VisibleAnywhere)
		float BaseLookUpRate;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
