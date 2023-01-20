// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "Slash/DebugMacros.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	/** 로그
	* UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));
	*/

	/** 스크린 로그
	* if (GEngine)
	* {
	* 	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, TEXT("GEngine Msg"));
	* }
	*/
	

	/** 드로우 디버그 */
	UWorld* World = GetWorld();
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();
	/** 드로우 스피어
	* if (World)
	* {
	* 	DrawDebugSphere(World, Location, 25.f, 24, FColor::Red, false, 30.f); // Sphere
	* }
	*/

	/** 드로우 라인
	* if(World)
	* {
	*   FVector Forward = GetActorForwardVector();
	*	DrawDebugLine(World, Location, Location + Forward * 100.f, FColor::Red, ture, -1.f, 0, 1.f);
	* }
	*/

	/** 드로우 포인트
	* if(World)
	* {
	*	DrawDebugPoint(World, Location + Forward * 100.f, 15.f, FColor::Red, ture);
	* }
	*/

	DRAW_SPHERE(GetActorLocation());
	// DRAW_LINE(Location, Location + Forward * 100.f);
	// DRAW_POINT(Location + Forward * 100.f);
	DRAW_VECTOR(Location, Location + Forward * 100.f);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/** 로그
	* UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);
	*/
	
	/** 스크린 로그
	* if (GEngine)
	* {
	* 	FString Name = GetName();
	* 	FString Message = FString::Printf(TEXT("DeltaTime: %f"), DeltaTime);
	* 	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, Name+Message);
	* }
	*/
	
}

