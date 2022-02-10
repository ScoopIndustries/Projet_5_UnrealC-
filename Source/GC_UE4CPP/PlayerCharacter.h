// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <GC_UE4CPP/AI/Food.h>
#include "AI/Waypoint.h"
#include <GC_UE4CPP/PlayerGameState.h> // A enlever pour le bien du projet !!!
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

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
		float BaseTurnRate;
	UPROPERTY(VisibleAnywhere)
		float BaseLookUpRate;
	UPROPERTY(VisibleAnywhere)
		float ValueZoom;
	UPROPERTY(VisibleAnywhere)
		float ValueProgressZoom = 50.f;
	UPROPERTY(VisibleAnywhere)
		float ValueZoomMin = 800.f;
	UPROPERTY(VisibleAnywhere)
		float ValueZoomMax = 200.f;
	UPROPERTY(VisibleAnywhere)
		float ConditionForZoom = 0.f;

	UPROPERTY(EditAnywhere)
		bool IsCarrying = false;

	UPROPERTY(VisibleAnywhere)
		FVector PlayerVelocity;

	UPROPERTY(VisibleAnywhere)
		class AFood* Food;

	UPROPERTY(VisibleAnywhere)
		class AWaypoint* Plate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
		float WalkSpeed = 450.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
		float CarrySpeed = 250.0f;

	UFUNCTION()
		FVector RecupPlayerVelocity();
	UFUNCTION()
		void PickUpObject();
	UFUNCTION()
		void DropObject();

	UFUNCTION()
		void CallbackComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void CallbackComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


protected:

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* SkeletalMesh;

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
	
	//fonction pour changer le zoom de la camera
	void CameraZoom(float Value);

	virtual void BeginPlay() override;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime") // A enlever pour le bien du projet !!!
		class APlayerGameState* PlayerGameState; // A enlever pour le bien du projet !!!
};
