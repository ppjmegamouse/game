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

	// �A�C�e�����o��������ꏊ
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;

	// �V�����A�C�e�����X�|�[������
	void SpawnPickup();

	// �A�C�e�����X�|�[��������Ԋu
	float SpawnDelay;

protected:

	// �o��������A�C�e��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	TSubclassOf<class APickup> WhatToSpawn;

	// �A�C�e�����o��������Ԋu
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayLow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayHigh;

	// �A�C�e�����o��������^�C�~���O���Ǘ�����
	FTimerHandle SpawnTimer;

public:

	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; };

	// �����ꏊ�������_���ŕԂ�
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();

	// �A�C�e���̃X�|�[�������邩�ǂ�����ݒ�
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SetSpawningActive(bool bShouldSpawn);
};
