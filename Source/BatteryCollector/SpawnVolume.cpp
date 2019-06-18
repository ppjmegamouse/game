// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnVolume.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Pickup.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
	// Tick�֐��̌Ăяo�����s��Ȃ�
	PrimaryActorTick.bCanEverTick = false;

	// WhereToSpawn�̐ݒ�
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	// WhereToSpawn�����[�g��
	RootComponent = WhereToSpawn;


	// ������
	SpawnDelayLow = 1.0f;
	SpawnDelayHigh = 4.5f;
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SpawnPickup();
}

void ASpawnVolume::SpawnPickup()
{
	// �X�|�[��������ꏊ�����߂�

	if (WhatToSpawn != NULL)
	{
		UWorld* const World = GetWorld();
		if (World)
		{
			// �X�|�[�������邽�߂̃p�����[�^�ݒ�
			FActorSpawnParameters SpawnParams;
			// �X�|�[��������I�[�i�[
			SpawnParams.Owner = this;
			// �X�|�[��������A�C�e���I�u�W�F�N�g�̏��L�҂ƃX�|�[���������I�u�W�F�N�g�̏��
			SpawnParams.Instigator = Instigator;

			// �ǂ��ɃX�|�[�������邩
			FVector SpawnLocation = GetRandomPointInVolume();
			FRotator SpawnRotation;

			// �X�|�[��������A�C�e���̉�]
			SpawnRotation.Yaw = FMath::FRand() * 360.0f;
			SpawnRotation.Roll = FMath::FRand() * 360.0f;
			SpawnRotation.Pitch = FMath::FRand() * 360.0f;

			// �A�C�e�����X�|�[��������
			APickup* const SpawnedPickup = World->SpawnActor<APickup>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
		}
	}

	// �X�|�[��������ۂ̂������̐ݒ�

	// ���Ԋu�Ő�������
}

FVector ASpawnVolume::GetRandomPointInVolume()
{
	// WhereToSpawn�̌��_
	FVector SpawnOrigin = WhereToSpawn->Bounds.Origin;

	// WhereToSpawn�͈̔�
	FVector SpawnExtent = WhereToSpawn->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);
}

void ASpawnVolume::SetSpawningActive(bool bShouldSpawn)
{
	if (bShouldSpawn)
	{

		UE_LOG(LogTemp, Warning, TEXT("true"));
		SpawnDelay = FMath::FRandRange(SpawnDelayLow, SpawnDelayHigh);
		GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
	}
	else
	{

		UE_LOG(LogTemp, Warning, TEXT("false"));
		GetWorldTimerManager().ClearTimer(SpawnTimer);
	}
}

