// Fill out your copyright notice in the Description page of Project Settings.


#include "GPPlayerController.h"
#include "GPPaperCharacter.h"

void AGPPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (IsLocalController())
	{
		InputComponent->BindAxis("MoveUp", this, &AGPPlayerController::OnMoveUp);
		InputComponent->BindAxis("MoveRight", this, &AGPPlayerController::OnMoveRight);
		InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AGPPlayerController::OnJump);
	}
}

void AGPPlayerController::OnMoveUp(float AxisValue)
{
	AGPPaperCharacter* ControlledGPPaperCharacter = Cast<AGPPaperCharacter>(GetCharacter());
	if (ControlledGPPaperCharacter)
	{
		ControlledGPPaperCharacter->OnMoveUp(AxisValue);
	}
}

void AGPPlayerController::OnMoveRight(float AxisValue)
{
	AGPPaperCharacter* ControlledGPPaperCharacter = Cast<AGPPaperCharacter>(GetCharacter());
	if (ControlledGPPaperCharacter)
	{
		ControlledGPPaperCharacter->OnMoveRight(AxisValue);
	}
}

void AGPPlayerController::OnJump()
{
	AGPPaperCharacter* ControlledGPPaperCharacter = Cast<AGPPaperCharacter>(GetCharacter());
	if (ControlledGPPaperCharacter)
	{
		ControlledGPPaperCharacter->OnJump();
	}
}