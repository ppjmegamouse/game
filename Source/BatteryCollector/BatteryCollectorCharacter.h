// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BatteryCollectorCharacter.generated.h"

UCLASS(config=Game)
class ABatteryCollectorCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	ABatteryCollectorCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

private:

	// �A�C�e��������ł���͈�
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Power", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* CollectionSphere;

	// �o�b�e���[�̒l�i���A���^�C���ɕω�������j
	UPROPERTY(VisibleAnywhere, Category = "Power")
	float CharacterPower;

protected:

	// �A�C�e�����W�{�^���������ꂽ�Ƃ��ɌĂяo�����B���W�͈͓��ɓ����Ă���Pickup�����W���ăo�b�e���[���񕜂�����B
	UFUNCTION(BlueprintCallable, Category = "Pickups")
	void CollectPickups();

	// �o�b�e���[�f�t�H���g�l�i�s�ρj
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float InitialPower;

	// �v���C���[�̈ړ����x�̊�l
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float BaseSpeed;

	// �v���C���[�̈ړ����x�̊�l
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float SpeedFactor;

public:

	// �A�C�e���̎��W�ł���͈͂�Ԃ�
	FORCEINLINE class USphereComponent* GetCollectionSphere() const { return CollectionSphere; }

	// �o�b�e���[�f�t�H���g�l�擾
	UFUNCTION(BlueprintPure, Category = "Power")
	float GetInitialPower();

	// �o�b�e���[�l�擾
	UFUNCTION(BlueprintPure, Category = "Power")
	float GetCharacterPower();

	// �o�b�e���[�l�X�V
	UFUNCTION(BlueprintCallable, Category = "Power")
	void UpdateCharacterPower(float PowerChange);

	// �G�l���M�[�l�ɂ���ăL�����N�^�[���b�V���̐F��ω�������(�����̎����̓u���[�v�����g�ōs��)
	UFUNCTION(BlueprintImplementableEvent, Category = "Power")
	void PowerChangeEffect();

};

