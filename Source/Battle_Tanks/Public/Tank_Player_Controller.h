// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank_Player_Controller.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANKS_API ATank_Player_Controller : public APlayerController
{
	GENERATED_BODY()

public:
	ATank * GetControlledTank() const;
	
	virtual void BeginPlay() override;
	
};
