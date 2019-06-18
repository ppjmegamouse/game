// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageObstacle.h"
#include "BatteryCollectorCharacter.h"


ADamageObstacle::ADamageObstacle()
{
	PrimaryActorTick.bCanEverTick = false;

	// ���b�V���̕��������ݒ�
	GetMesh()->SetSimulatePhysics(false);

	BatteryDamage = -30.0f;

	// �A�N�^�[�Ƃ̏Փˎ��̏�����o�^
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
