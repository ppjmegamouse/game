// Fill out your copyright notice in the Description page of Project Settings.

#include "TransformObstacle.h"
#include "Components/StaticMeshComponent.h"

ATransformObstacle::ATransformObstacle()
{
	PrimaryActorTick.bCanEverTick = true;

	// ���b�V���̕��������ݒ�
	GetMesh()->SetSimulatePhysics(false);

	// ��Q���͊g�傩��n�߂�
	scaleState_ = ScaleState::INCREASE;

	// �e�p�����[�^�̏����ݒ�
	SetInterval(0.01f);
	SetMaxScale(3.0f);
	SetMinScale(0.5f);
}

void ATransformObstacle::Tick(float DeltaTime)
{

	FVector vector = GetActorScale3D();
	// �Q�[����Tick���̎��ԍ����ւ̑Ή������ύX�l���Z�o
	float changeScale = ScaleInterval * DeltaTime;

	switch (scaleState_)
	{
	// ��Q���̊g�又��
	case ScaleState::INCREASE:
		vector.X += changeScale;
		vector.Y += changeScale;
		vector.Z += changeScale;
		break;
	// ��Q���̏k������
	case ScaleState::DECREASE:
		vector.X -= changeScale;
		vector.Y -= changeScale;
		vector.Z -= changeScale;
		break;
	case ScaleState::NEUTRAL:
		break;
	default:
		break;
	}

	SetActorScale3D(vector);

	if (vector.X >= MaxScale)
	{
		scaleState_ = ScaleState::DECREASE;
	}
	else if (vector.X <= MinScale)
	{
		scaleState_ = ScaleState::INCREASE;
	}
}
