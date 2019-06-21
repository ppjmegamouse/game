// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APickup::APickup()
{
	// Tick�֐����ŏ������s��Ȃ�
	PrimaryActorTick.bCanEverTick = false;

	// �I�u�W�F�N�g���������ꂽ���_�ŃA�N�e�B�u�ɂ��Ă���
	bIsActive = true;

	// �I�u�W�F�N�g�̃��b�V���R���|�[�l���g��ݒ肷��
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));

	// StaticMesh�R���|�[�l���g�����[�g�ɐݒ�
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

// bIsActive��Getter
bool APickup::IsActive()
{
	return bIsActive;
}

// bIsActive��Setter
void APickup::SetActive(bool MwwPickupState)
{
	bIsActive = MwwPickupState;
}

void APickup::WasCollected_Implementation()
{
	FString name = GetName();
	UE_LOG(LogTemp, Log, TEXT("You have collected %s"), *name);
}

