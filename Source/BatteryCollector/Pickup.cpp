// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APickup::APickup()
{
	// Tick関数内で処理を行わない
	PrimaryActorTick.bCanEverTick = false;

	// オブジェクトが生成された時点でアクティブにしておく
	bIsActive = true;

	// オブジェクトのメッシュコンポーネントを設定する
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));

	// StaticMeshコンポーネントをルートに設定
	RootComponent = PickupMesh;
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// bIsActiveのGetter
bool APickup::IsActive()
{
	return bIsActive;
}

// bIsActiveのSetter
void APickup::SetActive(bool MwwPickupState)
{
	bIsActive = MwwPickupState;
}

void APickup::WasCollected_Implementation()
{
	FString name = GetName();
	UE_LOG(LogTemp, Log, TEXT("You have collected %s"), *name);
}

