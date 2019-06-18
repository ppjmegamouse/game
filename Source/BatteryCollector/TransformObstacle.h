// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "TransformObstacle.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ATransformObstacle : public AObstacle
{
	GENERATED_BODY()

public:

	ATransformObstacle();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// 現在のオブジェクトの拡縮状態
	enum class ScaleState
	{
		None

		,INCREASE
		,DECREASE

		,NEUTRAL
	};

	ScaleState scaleState_ = ScaleState::None;


protected:

	// オブジェクトのサイズ切り替え間隔
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Obstacle")
	float ScaleInterval;

	// オブジェクトの最大倍率
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Obstacle")
	float MaxScale;

	// オブジェクトの最小倍率
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Obstacle")
	float MinScale;

public:

	// 各パラメータのGetter Setter

	float GetInterval() const { return ScaleInterval; };

	void SetInterval(float newInterval) { ScaleInterval = newInterval; };

	float GetMaxScale() const { return MaxScale; };

	void SetMaxScale(float newMaxScale) { MaxScale = newMaxScale; };

	float GetMinScale() const { return MinScale; };

	void SetMinScale(float newMinScale) { MinScale = newMinScale; };
};
