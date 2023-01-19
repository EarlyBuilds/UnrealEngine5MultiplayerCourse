// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ShooterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class COURSESHOOTER_API UShooterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties(float DeltaTime);

	virtual void NativeInitializeAnimation() override;
private:
	UPROPERTY(VisibleAnywhere, Category = Movement, meta =(AllowPrivateAcces = "True"))
	class AShooterCharacter* ShooterCharacter;

	/** Character Speed*/
	UPROPERTY(VisibleAnywhere, Category = Movement, meta = (AllowPrivateAcces = "True"))
	float Speed;

	/** Character In Air*/
	UPROPERTY(VisibleAnywhere, Category = Movement, meta = (AllowPrivateAcces = "True"))
	bool bIsInAir;

	/** Character Is Moving*/
	UPROPERTY(VisibleAnywhere, Category = Movement, meta = (AllowPrivateAcces = "True"))
	bool bIsAccelerating;
};
