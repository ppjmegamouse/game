// Fill out your copyright notice in the Description page of Project Settings.

#include "TransformObstacle.h"
#include "Components/StaticMeshComponent.h"

ATransformObstacle::ATransformObstacle()
{
	PrimaryActorTick.bCanEverTick = true;

	// ƒƒbƒVƒ…‚Ì•¨—‹““®Ý’è
	GetMesh()->SetSimulatePhysics(false);

	// áŠQ•¨‚ÍŠg‘å‚©‚çŽn‚ß‚é
	scaleState_ = ScaleState::INCREASE;

	// Šeƒpƒ‰ƒ[ƒ^‚Ì‰ŠúÝ’è
	SetInterval(0.01f);
	SetMaxScale(3.0f);
	SetMinScale(0.5f);
}

void ATransformObstacle::Tick(float DeltaTime)
{

	FVector vector = GetActorScale3D();
	// ƒQ[ƒ€‚ÌTick–ˆ‚ÌŽžŠÔ·•ª‚Ö‚Ì‘Î‰ž‚µ‚½•ÏX’l‚ðŽZo
	float changeScale = ScaleInterval * DeltaTime;

	switch (scaleState_)
	{
	// áŠQ•¨‚ÌŠg‘åˆ—
	case ScaleState::INCREASE:
		vector.X += changeScale;
		vector.Y += changeScale;
		vector.Z += changeScale;
		break;
	// áŠQ•¨‚Ìk¬ˆ—
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
