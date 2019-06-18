// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "DamageObstacle.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ADamageObstacle : public AObstacle
{
	GENERATED_BODY()
	
public:

	ADamageObstacle();

private:

	// BatteryCollectorCharacter�̐ڐG��ԊǗ��t���O
	bool IsHitBCCharacter;

protected:

	// �o�b�e���[�̃_���[�W��
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "BatteryDamage")
	float BatteryDamage;

	// �A�N�^�[�ڐG���̃f���Q�[�g�֐�
	UFUNCTION()
	void OnHit(class AActor* SelfActor, class AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

};
