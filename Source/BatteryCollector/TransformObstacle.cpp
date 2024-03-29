// Fill out your copyright notice in the Description page of Project Settings.

#include "TransformObstacle.h"

ATransformObstacle::ATransformObstacle()
{
	PrimaryActorTick.bCanEverTick = true;

	// メッシュの物理挙動設定
	GetMesh()->SetSimulatePhysics(false);

	// 障害物は拡大から始める
	scaleState_ = ScaleState::INCREASE;

	// 各パラメータの初期設定
	SetInterval(0.01f);
	SetMaxScale(3.0f);
	SetMinScale(0.5f);
}

void ATransformObstacle::Tick(float DeltaTime)
{

	FVector vector = GetActorScale3D();
	// ゲームのTick毎の時間差分への対応した変更値を算出
	float changeScale = ScaleInterval * DeltaTime;

	switch (scaleState_)
	{
	// 障害物の拡大処理
	case ScaleState::INCREASE:
		vector.X += changeScale;
		vector.Y += changeScale;
		vector.Z += changeScale;
		break;
	// 障害物の縮小処理
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
