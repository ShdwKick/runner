// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Runner2GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class RUNNER2_API ARunner2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		float GameTime = 0.0f;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		FTimerHandle timerHandle;

	UFUNCTION()
		void Timer();
	
};
