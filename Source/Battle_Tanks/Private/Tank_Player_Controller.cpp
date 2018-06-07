// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank_Player_Controller.h"


ATank *ATank_Player_Controller:: GetControlledTank() const
{
	
	return Cast <ATank>(GetPawn());
}

void ATank_Player_Controller:: BeginPlay()
{
	Super::BeginPlay();
	auto controlledtank = GetControlledTank();
	if(controlledtank)
	{
		
		UE_LOG(LogTemp, Warning, TEXT("%s Controlled"),*controlledtank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT(" No Tank Controlled"))
	}
}

void ATank_Player_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ATank_Player_Controller::AimTowardCrossHair()
{
	if(!GetControlledTank())
	{
		return;
	}
	if(GetControlledTank())
	{
		
	}
}
