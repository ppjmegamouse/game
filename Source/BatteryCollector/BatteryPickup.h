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

	// バッテリー回復量のGetter
	FORCEINLINE float GetBatteryPower() const { return BatteryPower; };

	// バッテリー回復量のSetter
	void SetPower(float newPower) { BatteryPower = newPower; };

	void WasCollected_Implementation() override;

protected:

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Power")
	float BatteryPower;
	
};
