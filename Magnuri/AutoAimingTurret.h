// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurretBase.h"
#include "AutoAimingTurret.generated.h"

/**
 * 
 */
UCLASS()
class MAGNURI_API AAutoAimingTurret : public ATurretBase
{
	GENERATED_BODY()

public:
	AAutoAimingTurret();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;


};
