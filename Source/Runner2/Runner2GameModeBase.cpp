// Copyright Epic Games, Inc. All Rights Reserved.


#include "Runner2GameModeBase.h"

void ARunner2GameModeBase::BeginPlay()
{
	GetWorldTimerManager().SetTimer(timerHandle,this,&ARunner2GameModeBase::Timer,1.0f,true);
}

void ARunner2GameModeBase::Timer()
{
	if(timerHandle.IsValid())
	{
		GameTime+=1;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1,1.0f,FColor::Emerald,"InvalidTimer -> ARunner2GameModeBase");
	}
}
