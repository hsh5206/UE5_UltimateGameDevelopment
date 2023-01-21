// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "Slash/DebugMacros.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

	/** Component */
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//movement rate in units of cm/s
	float MovementRate = 50.f;
	float RotationRate = 45.f;

	/** 荤牢窃荐 */
	RunningTime += DeltaTime;
	float DeltaZ = TransformedSin(RunningTime);
	AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));

}

float AItem::TransformedSin(float value)
{
	return  Amplitude * FMath::Sin(value * TimeConstant); // 加档, 气
}

float AItem::TransformedCos(float value)
{
	return  Amplitude * FMath::Cos(value * TimeConstant); // 加档, 气
}