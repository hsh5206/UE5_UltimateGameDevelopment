// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "Slash/DebugMacros.h"

AItem::AItem() : Amplitude(0.25f)
{
	PrimaryActorTick.bCanEverTick = true;
	
	// Amplitude = 0.25f;

	/** template Function */
	Avg<int32>(1, 3);
	Avg<float>(3.45f, 7.86f);

	/** Component */
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	// SetActorLocation(FVector(0.f, 0.f, 50.f));
	// SetActorRotation(FRotator(0.f, 45.f, 0.f));

	// UWorld* World = GetWorld();
	// FVector Location = GetActorLocation();
	// FVector Forward = GetActorForwardVector();

	///** 드로우 디버그 */
	// DRAW_SPHERE(GetActorLocation());
	// DRAW_VECTOR(Location, Location + Forward * 100.f);

}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//movement rate in units of cm/s
	float MovementRate = 50.f;
	float RotationRate = 45.f;
	/** MovementRate* DeltaTime = > (cm / s) * (s / frame) = (cm / frame) */
	// AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	// AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));

	/** 사인함수 */
	RunningTime += DeltaTime;
	float DeltaZ = TransformedSin(RunningTime);
	AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));

	DRAW_SPHERE_SINGLEFRAME(GetActorLocation());
	DRAW_VECTOR_SINGLEFRAME(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	DRAW_POINT_SINGLEFRAME(AvgVector);
	// FRotator AvgRotator = Avg<FRotator>(GetActorRotation(), FRotator::ZeroRotator); didnt provide '/' operator
}

float AItem::TransformedSin(float value)
{
	return  Amplitude * FMath::Sin(value * TimeConstant); // 속도, 폭
}

float AItem::TransformedCos(float value)
{
	return  Amplitude * FMath::Cos(value * TimeConstant); // 속도, 폭
}