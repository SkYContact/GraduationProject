// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "GPPaperCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GRADUATIONPROJECT_API AGPPaperCharacter : public APaperCharacter
{
	GENERATED_BODY()
	
public:

	virtual void Tick(float DeltaSeconds) override;

	void OnMoveUp(float AxisValue);

	void OnMoveRight(float AxisValue);

	void OnJump();
};
