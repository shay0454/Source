// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingTurret.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

AMovingTurret::AMovingTurret()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);

    TurMesh = GetTurretMesh();

    TurnSpeed = 30.f;

}


void AMovingTurret::BeginPlay()
{
    Super::BeginPlay();

    TurretController = Cast<APlayerController>(GetController());
}

void AMovingTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMovingTurret::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("UpDown"),this,&AMovingTurret::Forward);
    PlayerInputComponent->BindAxis(TEXT("Turn"),this,&AMovingTurret::Turn);
    
}

void AMovingTurret::Turn(float Vaule)
{
    double DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

    FRotator DeltaRotation(0.f);
    DeltaRotation.Yaw += Vaule*DeltaTime*TurnSpeed;
    AddActorLocalRotation(DeltaRotation,true);

}

void AMovingTurret::Forward(float Vaule)
{
    double DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
    FVector DeltaLocation(0.f);
    DeltaLocation.X += Vaule*DeltaTime*ForwardSpeed;
    
}