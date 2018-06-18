// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UTankAimingComponent::SetBarrel(UStaticMeshComponent *BarrelToSet)
{
	Barrel = BarrelToSet;
}



void UTankAimingComponent::AimAt(FVector HitLocation,float LaunchSpeed)
{ 
	if(!Barrel) {return;}
	

		FVector LaunchVelocity;
		FVector StartLocation = Barrel->GetSocketLocation(FName("BarrelEnd"));
		 

		if (UGameplayStatics::SuggestProjectileVelocity(this,LaunchVelocity,StartLocation, HitLocation,LaunchSpeed,false,0,0,ESuggestProjVelocityTraceOption::DoNotTrace))
		{
			auto AimDirection = LaunchVelocity.GetSafeNormal();
			
			MoveBarrelTowards(AimDirection);
		}

		
	

	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimatRotation = AimDirection.Rotation();
	auto CurrentTank = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s is firing at launch speed %s"), *CurrentTank, *AimatRotation.ToString())
}


