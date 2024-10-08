// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

class UBehaviorTree;
class UBlackboardComponent;

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

public:     
    
    virtual void Tick(float DeltaTime) override;

    bool IsDead() const;

protected:

    virtual void BeginPlay() override;

private:

    APawn* PlayerPawn;

    // Moved to behavior tree
    //UPROPERTY(EditDefaultsOnly)
    //float AcceptanceRadius = 200.0;

    UPROPERTY(EditAnywhere)
    UBehaviorTree* AIBehavior;

    UBlackboardComponent* BlackboardComponent;
};
