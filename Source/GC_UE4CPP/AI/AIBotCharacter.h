// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Food.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* NextWaypoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)	
		FName socket;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		AActor* FoodActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)	
		USkeletalMeshComponent* SKmesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class AFood> FoodClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<AActor*> ListOfPoint;



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
