// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "RunnerPlayerController.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ARunnerCharacter::ARunnerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARunnerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARunnerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovementTick(DeltaTime);

}

// Called to bind functionality to input
void ARunnerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Right",IE_Pressed,this,&ARunnerCharacter::MoveRight);
	PlayerInputComponent->BindAction("Left",IE_Pressed,this,&ARunnerCharacter::MoveLeft);

	PlayerInputComponent->BindAction("Roll",IE_Pressed,this,&ARunnerCharacter::Roll);
	PlayerInputComponent->BindAction("Roll",IE_Released,this,&ARunnerCharacter::StopRoll);

}

void ARunnerCharacter::MovementTick(float DeltaSeconds)
{
	if(!GetMesh()->GetRelativeLocation().Equals(TargetLocation,25))
	{
		if(direction==EDirections::Right)
		{
			CharacterMovement(DeltaSeconds,DeltaLocationValue);
		}
		else if(direction==EDirections::Left)
		{
			CharacterMovement(DeltaSeconds,-DeltaLocationValue);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(0,15.0f,FColor::Red,TEXT("Incorrect Dirrection -> RunnerCgaracter.cpp"));
		}
	}
}

void ARunnerCharacter::CharacterMovement(float DeltaSeconds,float DeltaValue)
{

}

void ARunnerCharacter::MoveRight()
{
	direction = EDirections::Right;
}

void ARunnerCharacter::MoveLeft()
{
	direction = EDirections::Left;
}

void ARunnerCharacter::Roll()
{
	 bIsNeedRoll=true;
}

void ARunnerCharacter::StopRoll()
{
	bIsNeedRoll=true;
}

