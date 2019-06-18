// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryPickup.h"

ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);
	SetPower(150.0);
}

void ABatteryPickup::WasCollected_Implementation()
{
	Super::WasCollected_Implementation();

	UE_LOG(LogTemp, Warning, TEXT("C++ called"));

	// 拾われたので、オブジェクトを破棄
	Destroy();
}
