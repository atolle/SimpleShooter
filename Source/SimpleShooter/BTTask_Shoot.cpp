// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "SimpleShooter/ShooterCharacter.h"
#include "SimpleShooter/ShooterAIController.h"
#include "AIController.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AShooterAIController* AIController = Cast<AShooterAIController>(OwnerComp.GetAIOwner());

	if (!AIController)
		return EBTNodeResult::Failed;

	AShooterCharacter* AIPawn = Cast<AShooterCharacter>(AIController->GetPawn());

	if (!AIPawn)
		return EBTNodeResult::Failed;

	AIPawn->Shoot();

	return EBTNodeResult::Succeeded;
}