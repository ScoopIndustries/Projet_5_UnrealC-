// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Food.h"
#include "../PlayerGameState.h"
#include "AIBotCharacter.generated.h"

UCLASS()
class GC_UE4CPP_API AAIBotCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIBotCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCarrying;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)	
		FName socket;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		AActor* FoodActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)	
		USkeletalMeshComponent* SKmesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int CycleIndex;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class APlayerGameState* PlayerGameState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
		float WalkSpeed = 450.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
		float CarrySpeed = 250.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class AFood> FoodClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Get Item on ground
	void GetFromTheGround();
	//Put Item on ground
	void PutOnTheGround();
};
