// Fill out your copyright notice in the Description page of Project Settings.


#include "ManualAimingTurret.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"


AManualAimingTurret::AManualAimingTurret(){
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);

    TurMesh = GetTurretMesh();

    UpDownSpeed = 50.f;
    TurnSpeed = 30.f;
    UpLimit = 30.f;
    DownLimit = -10.f;
}

void AManualAimingTurret::BeginPlay()
{
    Super::BeginPlay();

    Turret_Controller = Cast<APlayerController>(GetController());
}

void AManualAimingTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AManualAimingTurret::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("UpDown"),this,&AManualAimingTurret::UpDown);
    PlayerInputComponent->BindAxis(TEXT("Turn"),this,&AManualAimingTurret::Turn);
    
}

void AManualAimingTurret::UpDown(float Vaule)
{
    double DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

    if(TurMesh == nullptr) return;
    
	FRotator CntLocalRotation = TurMesh->GetRelativeRotation();

    CntLocalRotation.Roll += Vaule * DeltaTime * UpDownSpeed;
	CntLocalRotation.Roll = FMath::ClampAngle(CntLocalRotation.Roll,DownLimit,UpLimit);

    TurMesh->SetRelativeRotation(CntLocalRotation,true);

	UE_LOG(LogTemp,Display,TEXT("now : %f"),TurMesh->GetRelativeRotation().Roll);
}

void AManualAimingTurret::Turn(float Vaule)
{
    double DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

    FRotator DeltaRotation(0.f);
    DeltaRotation.Yaw += Vaule*DeltaTime*TurnSpeed;
    AddActorLocalRotation(DeltaRotation,true);

}