// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GPPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GRADUATIONPROJECT_API AGPPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;
	void OnMoveUp(float AxisValue);
	void OnMoveRight(float AxisValue);
	void OnJump();
};
