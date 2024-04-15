// Fill out your copyright notice in the Description page of Project Settings.


#include "AutoAimingTurret.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

AAutoAimingTurret::AAutoAimingTurret()
{
    PrimaryActorTick.bCanEverTick = true;
}
void AAutoAimingTurret::BeginPlay()
{
    Super::BeginPlay();
    
}

void AAutoAimingTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if(CheckInRange(HitResult)){
        UE_LOG(LogTemp,Display,TEXT("check"));
    }
}

bool AAutoAimingTurret::CheckInRange(FHitResult& OutHitResult)
{
    UStaticMeshComponent* TurMesh = GetTurretMesh();
    FVector Start = TurMesh->GetComponentLocation();
	FVector End = Start + TurMesh->GetForwardVector()*FireRange;

	DrawDebugSphere(GetWorld(),Start,FireRange,10,FColor::Blue,false,0.5);
	
	FCollisionShape Sphere= FCollisionShape::MakeSphere(FireRange);
	return GetWorld()->SweepSingleByChannel(
			OutHitResult, 
			Start, End, 
			FQuat::Identity, 
			ECC_GameTraceChannel1, 
			Sphere
	);
}
