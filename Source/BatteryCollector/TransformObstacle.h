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

	// ���݂̃I�u�W�F�N�g�̊g�k���
	enum class ScaleState
	{
		None

		,INCREASE
		,DECREASE

		,NEUTRAL
	};

	ScaleState scaleState_ = ScaleState::None;


protected:

	// �I�u�W�F�N�g�̃T�C�Y�؂�ւ��Ԋu
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Obstacle")
	float ScaleInterval;

	// �I�u�W�F�N�g�̍ő�{��
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Obstacle")
	float MaxScale;

	// �I�u�W�F�N�g�̍ŏ��{��
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Obstacle")
	float MinScale;

public:

	// �e�p�����[�^��Getter Setter

	float GetInterval() const { return ScaleInterval; };

	void SetInterval(float newInterval) { ScaleInterval = newInterval; };

	float GetMaxScale() const { return MaxScale; };

	void SetMaxScale(float newMaxScale) { MaxScale = newMaxScale; };

	float GetMinScale() const { return MinScale; };

	void SetMinScale(float newMinScale) { MinScale = newMinScale; };
};
