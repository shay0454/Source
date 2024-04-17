// Fill out your copyright notice in the Description page of Project Settings.


#include "AutoAimingTurret.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Components/PrimitiveComponent.h"

AAutoAimingTurret::AAutoAimingTurret()
{
    PrimaryActorTick.bCanEverTick = true;

	FireRange = 400.f;

}
void AAutoAimingTurret::BeginPlay()
{
    Super::BeginPlay();
    TurMesh = GetTurretMesh();

}

void AAutoAimingTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
	bool IsInRange = CheckInRange(HitResult);
	UE_LOG(LogTemp,Display,TEXT("%d"),IsInRange);
	if(!IsInRange)return;
	UE_LOG(LogTemp,Display,TEXT("%s"),*HitResult.BoneName.ToString());
    /*if(IsInRange && HitResult.GetActor()){
		UE_LOG(LogTemp,Display,TEXT("Hit"));
		if(!HitResult.GetActor()) return;
		RotateTurret(HitResult.GetActor()->GetActorLocation());
	}
	else{UE_LOG(LogTemp,Display,TEXT("Not Hit"));}*/
}

bool AAutoAimingTurret::CheckInRange(FHitResult& OutHitResult)
{

	DrawDebugSphere(GetWorld(),GetActorLocation(),FireRange,10,FColor::Blue,false,0.5);
	
	FCollisionShape Sphere= FCollisionShape::MakeSphere(FireRange/2);

	return GetWorld()->SweepSingleByChannel(
			OutHitResult, 
			GetActorLocation(),
			GetActorLocation()+GetActorForwardVector()*FireRange, 
			FQuat::Identity, 
			ECC_GameTraceChannel1, 
			Sphere
	);
}
