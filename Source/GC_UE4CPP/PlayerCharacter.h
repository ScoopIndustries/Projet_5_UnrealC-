// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Runtime/Engine/Classes/Camera/CameraComponent.h>
#include <Runtime/Engine/Classes/GameFramework/SpringArmComponent.h>
#include <Runtime/Engine/Classes/Components/BoxComponent.h>
#include "PlayerCharacter.generated.h"

UCLASS()
class GC_UE4CPP_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	// Sets default values for this character's properties
	APlayerCharacter();

	UPROPERTY(VisibleAnywhere)
		float ValueZoom;
	UPROPERTY(VisibleAnywhere)
		float ValueProgressZoom = 50.f;

protected:

	UPROPERTY(VisibleAnywhere)
		UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* CameraFollow;

	// fonction pour avancer / reculer
	void MoveForward(float Value);

	// fonction pour right / left
	void MoveRight(float Value);

	void CameraZoom(float Value);

	virtual void BeginPlay() override;

public:	

	UPROPERTY(VisibleAnywhere)
		float BaseTurnRate;

	UPROPERTY(VisibleAnywhere)
		float BaseLookUpRate;

	UFUNCTION()
		void CallbackComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void CallbackComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
