// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurretBase.h"
#include "ManualAimingTurret.generated.h"

/**
 * 
 */
UCLASS()
class MAGNURI_API AManualAimingTurret : public ATurretBase
{
	GENERATED_BODY()
	
public:
	AManualAimingTurret();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;

	UStaticMeshComponent* TurMesh;
	void UpDown(float Vaule);
	void Turn(float Vaule);

	APlayerController* Turret_Controller;

};
