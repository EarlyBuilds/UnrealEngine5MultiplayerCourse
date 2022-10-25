// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Begin Play"));

	//setting and printing a int
	int myInt{ 42 };
	UE_LOG(LogTemp, Warning, TEXT("int myInt: %d"), myInt);

	//setting a printing a float
	float myFloat{ 3.14159f };
	UE_LOG(LogTemp, Warning, TEXT("float myFloat: %f"), myFloat);

	//setting and printing a double
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

}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

