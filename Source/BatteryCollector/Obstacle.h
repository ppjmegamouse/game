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

	// レベル上での表示メッシュ
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Obstaticle", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ObstaticleMesh;

public:

	// メッシュの返却
	FORCEINLINE UStaticMeshComponent* GetMesh() const { return ObstaticleMesh; };
};
