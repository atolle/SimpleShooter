// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "SimpleShooter/ShooterCharacter.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (AIBehavior && PlayerPawn)
	{
		RunBehaviorTree(AIBehavior);

		BlackboardComponent = GetBlackboardComponent();

		BlackboardComponent->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
		
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Moved to BT services
	//if (LineOfSightTo(PlayerPawn))
	//{
		// Moved to behavior tree
		/*MoveToActor(PlayerPawn, AcceptanceRadius);
		SetFocus(PlayerPawn);*/


		// Moved to BT services
		//BlackboardComponent->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
		//BlackboardComponent->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
		//return;
	//}

	// Moved to behavior tree
	//ClearFocus(EAIFocusPriority::Gameplay);
	//StopMovement();

	// Moved to BT services
	//BlackboardComponent->ClearValue(TEXT("PlayerLocation"));
	
}

bool AShooterAIController::IsDead() const
{
	AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(GetPawn());

	if (ShooterCharacter)
		return ShooterCharacter->IsDead();

	return true;
}