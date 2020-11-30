// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

private:

	void MoveForward(float AxisValue);

	void MoveRight(float AxisValue);

	void LookUpRate(float AxisValue);

	void LookRightRate(float AxisValue);

	UPROPERTY(EditAnywhere)
	float RotationRate = 10.0;
	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100.0;
	UPROPERTY(VisibleAnywhere)
	float Health;

	// EditDefaultsOnly because we don't want to allow edit of this at runtime
	// This is so that we can pass the BP class we want from Blueprint, this is easier than trying to do so
	// through C++
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// BlueprintPure vs BlueprintCallable
	// const because we don't want IsDead() to change any state when called
	// BlueprintPure and const often go hand-in-hand because Pure should always return same result (doesn't change anything)
	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void Shoot();

};
