// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageObstacle.h"
#include "BatteryCollectorCharacter.h"


ADamageObstacle::ADamageObstacle()
{
	PrimaryActorTick.bCanEverTick = false;

	// メッシュの物理挙動設定
	GetMesh()->SetSimulatePhysics(false);

	BatteryDamage = -30.0f;

	// アクターとの衝突時の処理を登録
	OnActorHit.AddDynamic(this, &ADamageObstacle::OnHit);

	IsHitBCCharacter = false;
}

void ADamageObstacle::OnHit(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult & Hit)
{
	ABatteryCollectorCharacter* BCCharacter = Cast<ABatteryCollectorCharacter>(OtherActor);
	if (BCCharacter &&
		!IsHitBCCharacter)
	{
		IsHitBCCharacter = true;

		BCCharacter->UpdateCharacterPower(BatteryDamage);
	}
	else
	{
		IsHitBCCharacter = false;
	}
}
