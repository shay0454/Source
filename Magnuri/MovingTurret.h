// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurretBase.h"
#include "MovingTurret.generated.h"

/**
 * 
 */
UCLASS()
class MAGNURI_API AMovingTurret : public ATurretBase
{
	GENERATED_BODY()
	
public:
	AMovingTurret();

protected:
	APlayerController* TurretController;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, Category = "Move")
	float ForwardSpeed = 40.f;
	UStaticMeshComponent* TurMesh;

	void Turn(float Vaule);
	void Forward(float Vaule);
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
