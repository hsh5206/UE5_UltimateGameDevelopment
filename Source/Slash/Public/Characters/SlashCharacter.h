// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SlashCharacter.generated.h"

class UCapsuleComponent;
class USkeletaMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class SLASH_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(Visibleanywhere)
	USpringArmComponent* SpringArm;
	UPROPERTY(Visibleanywhere)
	UCameraComponent* Camera;

public:
	void MoveForward(float value);
	void MoveRight(float value);
	void Turn(float value);
	void LookUp(float value);
};
