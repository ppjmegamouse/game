// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BatteryCollectorGameMode.generated.h"

UENUM(BlueprintType)
enum class EBatteryPlayState : uint8
{
	EPlaying		// ゲームプレイ中
	,EGameOver		// ゲームオーバー
	,EWon			// ゲームクリア
	,EUnknown		// 上記以外
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

	// 現在のゲームステート
	EBatteryPlayState CurrentState;

	// レベル内に存在するSpawnVolumeを保持する
	TArray<class ASpawnVolume*> SpawnVolumeActors;

	// ステートに応じて処理を変えるためのハンドラ
	void HandleNewState(EBatteryPlayState NewState);


protected:

	// バッテリーが減少していくスピード
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
	float DecayRate;

	// 勝利するために必要なバッテリー量
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
	float PowerToWin;

	// HUD画面に必要なWidgetクラス
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	// HUDのインスタンス
	UPROPERTY()
	class UUserWidget* CurrentWidget;
};



