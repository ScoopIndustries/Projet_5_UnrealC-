// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Runtime/Engine/Classes/Components/BoxComponent.h>
#include "Chest.generated.h"

UCLASS()
class GC_UE4CPP_API AChest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* StaticMeshChestBaseTop;

	UPROPERTY(VisibleAnywhere)
		UBoxComponent* BoxCollision;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class APlayerCharacter* PlayerCharacter;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class APlayerGameState* PlayerGameState;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void CallbackComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
