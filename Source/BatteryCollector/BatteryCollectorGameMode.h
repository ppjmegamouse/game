// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BatteryCollectorGameMode.generated.h"

UENUM(BlueprintType)
enum class EBatteryPlayState : uint8
{
	EPlaying		// �Q�[���v���C��
	,EGameOver		// �Q�[���I�[�o�[
	,EWon			// �Q�[���N���A
	,EUnknown		// ��L�ȊO
};


UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Power")
	float GetPowerToWin() const;

	UFUNCTION(BlueprintPure, Category = "Power")
	EBatteryPlayState GetCurrentState() const;

	void SetCurrentState(EBatteryPlayState NewState);

private:

	// ���݂̃Q�[���X�e�[�g
	EBatteryPlayState CurrentState;

	// ���x�����ɑ��݂���SpawnVolume��ێ�����
	TArray<class ASpawnVolume*> SpawnVolumeActors;

	// �X�e�[�g�ɉ����ď�����ς��邽�߂̃n���h��
	void HandleNewState(EBatteryPlayState NewState);


protected:

	// �o�b�e���[���������Ă����X�s�[�h
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
	float DecayRate;

	// �������邽�߂ɕK�v�ȃo�b�e���[��
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
	float PowerToWin;

	// HUD��ʂɕK�v��Widget�N���X
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	// HUD�̃C���X�^���X
	UPROPERTY()
	class UUserWidget* CurrentWidget;
};



