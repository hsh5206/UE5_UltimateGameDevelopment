// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "Characters/CharacterTypes.h"
#include "Enemy.generated.h"

UCLASS()
class SLASH_API AEnemy : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	AEnemy();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;

	UPROPERTY(EditAnywhere, Category = Montages)
	UAnimMontage* HitReactMontage;
	UPROPERTY(EditAnywhere, Category = Montages)
	UAnimMontage* DeathMontage;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser);

protected:
	virtual void BeginPlay() override;

	void Die();
	
	UPROPERTY(BlueprintReadOnly)
	EDeathPose DeathPose = EDeathPose::EDP_Alive;

private:
	void PlayHitReactMontage();
	UPROPERTY(EditAnywhere, Category = Sounds)
	USoundBase* HitSound;
	UPROPERTY(EditAnywhere, Category = VisualEffects)
	UParticleSystem* HitParticle;

	UPROPERTY(VisibleAnywhere)
	class UAttributeComponent* Attributes;
	UPROPERTY(VisibleAnywhere)
	class UHealthBarComponent* HealthBarWidget;
	
	UPROPERTY()
	AActor* CombatTarget;
	UPROPERTY(EditAnywhere)
	double CombatRadius = 500.f;

};
