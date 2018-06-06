// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Engine/World.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	GetPlayersTank();
	ATank *AITank = GetControlledTank();
	ATank *PlayersTank= GetPlayersTank();
	if (AITank)
	{
		UE_LOG(LogTemp,Warning,TEXT("%s is controlled by AI"),*AITank->GetName());
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("No tank found for AI"));
	}
	if (PlayersTank&&AITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s found %s"),*AITank->GetName() ,*PlayersTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s did not find a player"),*AITank->GetName());
	}
}

ATank * ATankAiController::GetControlledTank() const
{
	return Cast<ATank> (GetPawn());
}

ATank * ATankAiController::GetPlayersTank() const
{
	auto FirstController = GetWorld()->GetFirstPlayerController();
		return Cast <ATank> (FirstController->GetPawn());
	
}

