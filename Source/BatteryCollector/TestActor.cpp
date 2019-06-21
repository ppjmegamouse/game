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

	// ���b�V���R���|�[�l���g�̃C���X�^���X�𐶐�
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));

	// ���b�V���f�[�^�̓ǂݍ��݂�����������mesh�Ƀ��b�V����ݒ�
	// ConstructorHelpers::FObjectFinder<UStaticMesh> staticMeshAsset(TEXT("/Engine/EngineMeshes/Sphere.Sphere"));
	// ConstructorHelpers::FObjectFinder<UMaterialInterface> materialAsset(TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"));

	// if (staticMeshAsset.Succeeded())
	// {
		// ���[�h�������b�V���ƃ}�e���A�����Z�b�g
		// mesh->SetStaticMesh(staticMeshAsset.Object);
		// mesh->SetMaterial(0, materialAsset.Object);

		// �����V�~�����[�V�������I���ɂ���
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

