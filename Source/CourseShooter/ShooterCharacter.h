// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class COURSESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Called for forward and backward input
	void MoveForward(float Value);

	//Called for side to side input
	void MoveRight(float Value);

	//Turn Rate
	void TurnAtRate(float Rate);

	//LookUpRate
	void LookUpAtRate(float Rate);

	//Called when Fire Weapon button is pressed
	void FireWeapon();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	/// <summary>
	/// Camera boom positioning the camera behind the character
	/// </summary>
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	//Camera following player
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	//Base Turn rate value
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseTurnRate;

	//Base LookUp rate value
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseLookUpRate;

	//Weapon Fire Sound
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = Weapon, meta = (AllowPrivateAccess = "true"))
	class USoundCue* FireSound;

	//Muzzle Flash Particle
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon, meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* MuzzleFlash;

	//Weapon Fire Montage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon, meta = (AllowPrivateAccess = "true"))
		class UAnimMontage* HipFireMontage;

public:
	/** Returns CameraBoom subobject*/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE UCameraComponent* GetFollowCamera() const {return FollowCamera;}
};
