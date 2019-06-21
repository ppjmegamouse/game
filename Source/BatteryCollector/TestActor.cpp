// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActor.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
//#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// メッシュコンポーネントのインスタンスを生成
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));

	// メッシュデータの読み込みが成功したらmeshにメッシュを設定
	// ConstructorHelpers::FObjectFinder<UStaticMesh> staticMeshAsset(TEXT("/Engine/EngineMeshes/Sphere.Sphere"));
	// ConstructorHelpers::FObjectFinder<UMaterialInterface> materialAsset(TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"));

	// if (staticMeshAsset.Succeeded())
	// {
		// ロードしたメッシュとマテリアルをセット
		// mesh->SetStaticMesh(staticMeshAsset.Object);
		// mesh->SetMaterial(0, materialAsset.Object);

		// 物理シミュレーションをオンにする
		// mesh->SetSimulatePhysics(true);
	// }
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

