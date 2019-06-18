// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickup : public APickup
{
	GENERATED_BODY()

public:

	ABatteryPickup();

	// �o�b�e���[�񕜗ʂ�Getter
	FORCEINLINE float GetBatteryPower() const { return BatteryPower; };

	// �o�b�e���[�񕜗ʂ�Setter
	void SetPower(float newPower) { BatteryPower = newPower; };

	void WasCollected_Implementation() override;

protected:

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Power")
	float BatteryPower;
	
};
