// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AttributeComponent.h"

UAttributeComponent::UAttributeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UAttributeComponent::ReciveDamage(float Damage)
{
	Health = FMath::Clamp(Health - Damage, 0.f, MaxHealth);
	if (Health == 0)
	{
		// Death
	}
}

float UAttributeComponent::GetHealthPercent()
{
	return Health/MaxHealth;
}
