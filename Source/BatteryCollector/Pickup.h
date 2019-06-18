// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// ���x����ŏE���郁�b�V��
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;

public:

	// �E������郁�b�V����Ԃ�
	FORCEINLINE UStaticMeshComponent* GetMesh() const { return PickupMesh; };

	// ���̃A�C�e�����E���邩�ǂ����̊m�F�p
	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsActive();

	// ���̃A�C�e�����E���邩�ǂ�����ݒ肷��
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool MwwPickupState);

	// �A�C�e��������ɌĂяo�����(�����̓u���[�v�����g���ōs����)
	UFUNCTION(BlueprintNativeEvent, Category = "Pickup")
	void WasCollected();
	virtual void WasCollected_Implementation();

protected:

	// ���̃A�C�e�����E���邩�ǂ���
	bool bIsActive;
};
