// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h" 	
#include "Engine/SkeletalMeshSocket.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
AShooterCharacter::AShooterCharacter() :
	BaseTurnRate(45.f),
	BaseLookUpRate(45.f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Setting up Camera boom (pulls in towards the character if there si a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.f; // distance between character and camera
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); //Setup and attach camera to the SpringArm
	FollowCamera->bUsePawnControlRotation = false; //Camera Doesn't rotate relative to SpringArm

	// this code isnt used because i dont like it.
	// freelook is a better option.
	//// When Camera moves the character doesnt move with it. only the camera.
	//bUseControllerRotationPitch = false;
	//bUseControllerRotationYaw = false;
	//bUseControllerRotationRoll = false;

	//// Set Orientate To Movement	
	// GetCharacterMovement()->bOrientRotationToMovement = true;

	//// Rotation Rate
	// GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Begin Play"));

	// Ignore this just learning how to make variables and print them to log.
	
	// Setting and printing a int
	int myInt{ 42 };
	UE_LOG(LogTemp, Warning, TEXT("int myInt: %d"), myInt);

	// Setting a printing a float
	float myFloat{ 3.14159f };
	UE_LOG(LogTemp, Warning, TEXT("float myFloat: %f"), myFloat);

	// Setting and printing a double
	double myDouble{ 0.000756 };
	UE_LOG(LogTemp, Warning, TEXT("double myDouble: %lf"), myDouble);

	//setting and print a char
	char myChar('J');
	UE_LOG(LogTemp, Warning, TEXT("char myChar: %c"), myChar);

	//setting and print a widechar
	wchar_t wideChar{L'J'};
	UE_LOG(LogTemp, Warning, TEXT("wchar_t wideChar: %lc"), wideChar);

	//setting and printing a boolean
	bool myBool{true};
	UE_LOG(LogTemp, Warning, TEXT("bool myBool: %d"), myBool);

	//printing multiple things at once
	UE_LOG(LogTemp, Warning, TEXT("int: %d, float: %f, bool: %d"), myInt, myFloat, myBool);

	//setting and printing a string
	FString myString{ TEXT("My first c++ string!") };
	UE_LOG(LogTemp, Warning, TEXT("FString myString: %s"), *myString);

	//get name of the current object
	UE_LOG(LogTemp, Warning, TEXT("Name of instance: %s"), *GetName());

	//The end of learning thing.
}

//Fire Weapon Function
void AShooterCharacter::FireWeapon() {
	UE_LOG(LogTemp, Warning, TEXT("FireWeapon"));
	if (FireSound) {
		UGameplayStatics::PlaySound2D(this, FireSound);
	}
	const USkeletalMeshSocket* BarrelSocket = GetMesh()->GetSocketByName("BarrelSocket");
	if (BarrelSocket)
	{
		const FTransform SocketTransform = BarrelSocket->GetSocketTransform(GetMesh());
		if (MuzzleFlash) {
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MuzzleFlash, SocketTransform);
		}
		
		//
		FHitResult FireHit;
		const FVector Start{ SocketTransform.GetLocation() };
		const FQuat Rotation{ SocketTransform.GetRotation() };

		
		GetWorld()->LineTraceSingleByChannel() {

		}
	}
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && HipFireMontage)
	{
		AnimInstance->Montage_Play(HipFireMontage);
		AnimInstance->Montage_JumpToSection(FName("StartFire"));
	}
}

//Move Forward/Backward Function
void AShooterCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f)) {
		// code to find the forward direction
		const FRotator Rotation{ Controller->GetControlRotation() };
		const FRotator YawRotation{ 0,Rotation.Yaw,0 };
		const FVector Direction{ FRotationMatrix{YawRotation}.GetUnitAxis(EAxis::X)};
		AddMovementInput(Direction, Value);
	}
}

//Move Right/Left Function
void AShooterCharacter::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f)) {
		// code to find the right direction
		const FRotator Rotation{ Controller->GetControlRotation() };
		const FRotator YawRotation{ 0,Rotation.Yaw,0 };
		const FVector Direction{ FRotationMatrix{YawRotation}.GetUnitAxis(EAxis::Y) };
		AddMovementInput(Direction, Value);
	}
}

//Using DeltaTime because it is better than updating every frame.
void AShooterCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate* BaseTurnRate * GetWorld()->GetDeltaSeconds());

}

//Using DeltaTime because it is better than updating every frame.
void AShooterCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());

}

//Tick
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Function to bind input to functions
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//idfk what this does
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	//Movement
	PlayerInputComponent->BindAxis("MoveForward", this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AShooterCharacter::MoveRight);

	//Look for Gamepad
	PlayerInputComponent->BindAxis("TurnRate", this, &AShooterCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AShooterCharacter::LookUpAtRate);

	//Look for Mouse
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	//Character Jump
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//Character Fire Weapon
	PlayerInputComponent->BindAction("FireButton", IE_Released, this, &AShooterCharacter::FireWeapon);
}


