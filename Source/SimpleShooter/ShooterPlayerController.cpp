// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "SimpleShooter/ShooterCharacter.h"

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDClass);

	if (HUD)
		HUD->AddToViewport();
}

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	UUserWidget* EndScreen = CreateWidget(this, bIsWinner ? WinScreenClass : LoseScreenClass);

	if (EndScreen)
		EndScreen->AddToViewport();

	if (HUD)
		HUD->RemoveFromViewport();

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

bool AShooterPlayerController::IsDead() const
{
	AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(GetPawn());

	if (ShooterCharacter)
		return ShooterCharacter->IsDead();

	return true;
}