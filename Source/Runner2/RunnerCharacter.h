// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RunnerPlayerController.h"
#include "GameFramework/Character.h"
#include "RunnerCharacter.generated.h"

UCLASS()
class RUNNER2_API ARunnerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARunnerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

	//vars

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float DeltaLocationValue = 300.0f;

	UPROPERTY()
	ARunnerPlayerController *PlayerController;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bIsNeedRoll = false;
	
	//func

	// UFUNCTION()
	// 	void MovementTick(float DeltaSeconds);

	UFUNCTION()
		void CharacterMovement(float DeltaValue);
	
	UFUNCTION()
		void MoveRight();

	UFUNCTION()
		void MoveLeft();

	UFUNCTION()
		void Roll();

	UFUNCTION()
		void StopRoll();

	UFUNCTION()
		void RollDelay();
};