// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// ���x����ł̕\�����b�V��
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Obstaticle", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ObstaticleMesh;

public:

	// ���b�V���̕ԋp
	FORCEINLINE UStaticMeshComponent* GetMesh() const { return ObstaticleMesh; };
};
