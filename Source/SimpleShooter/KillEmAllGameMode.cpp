// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "SimpleShooter/ShooterAIController.h"
#include "SimpleShooter/ShooterPlayerController.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	if (!PawnKilled)
		return;

	AShooterPlayerController* PlayerController = Cast<AShooterPlayerController>(PawnKilled->GetController());

	if (PlayerController)
	{
		EndGame(false);
	}		

	for (AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
	{
		if (!Controller->IsDead())
			return;
	}

	// If we made it here then we are still alive and all other pawns are dead, so we won
	EndGame(true);
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}
