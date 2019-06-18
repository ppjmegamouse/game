// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// アイテムを出現させる場所
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;

	// 新しいアイテムをスポーンする
	void SpawnPickup();

	// アイテムをスポーンさせる間隔
	float SpawnDelay;

protected:

	// 出現させるアイテム
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	TSubclassOf<class APickup> WhatToSpawn;

	// アイテムを出現させる間隔
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayLow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayHigh;

	// アイテムを出現させるタイミングを管理する
	FTimerHandle SpawnTimer;

public:

	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; };

	// 発生場所をランダムで返す
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();

	// アイテムのスポーンをするかどうかを設定
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SetSpawningActive(bool bShouldSpawn);
};
