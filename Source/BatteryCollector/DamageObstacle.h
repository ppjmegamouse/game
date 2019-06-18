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

	// BatteryCollectorCharacterの接触状態管理フラグ
	bool IsHitBCCharacter;

protected:

	// バッテリーのダメージ量
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "BatteryDamage")
	float BatteryDamage;

	// アクター接触時のデリゲート関数
	UFUNCTION()
	void OnHit(class AActor* SelfActor, class AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

};
