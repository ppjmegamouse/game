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
	// Tick関数の呼び出しを行わない
	PrimaryActorTick.bCanEverTick = false;

	// WhereToSpawnの設定
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	// WhereToSpawnをルートに
	RootComponent = WhereToSpawn;


	// 初期化
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
	// スポーンさせる場所を決める

	if (WhatToSpawn != NULL)
	{
		UWorld* const World = GetWorld();
		if (World)
		{
			// スポーンさせるためのパラメータ設定
			FActorSpawnParameters SpawnParams;
			// スポーンさせるオーナー
			SpawnParams.Owner = this;
			// スポーンさせるアイテムオブジェクトの所有者とスポーンさせたオブジェクトの情報
			SpawnParams.Instigator = Instigator;

			// どこにスポーンさせるか
			FVector SpawnLocation = GetRandomPointInVolume();
			FRotator SpawnRotation;

			// スポーンさせるアイテムの回転
			SpawnRotation.Yaw = FMath::FRand() * 360.0f;
			SpawnRotation.Roll = FMath::FRand() * 360.0f;
			SpawnRotation.Pitch = FMath::FRand() * 360.0f;

			// アイテムをスポーンさせる
			APickup* const SpawnedPickup = World->SpawnActor<APickup>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
		}
	}

	// スポーンさせる際のもろもろの設定

	// 一定間隔で説明する
}

FVector ASpawnVolume::GetRandomPointInVolume()
{
	// WhereToSpawnの原点
	FVector SpawnOrigin = WhereToSpawn->Bounds.Origin;

	// WhereToSpawnの範囲
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

