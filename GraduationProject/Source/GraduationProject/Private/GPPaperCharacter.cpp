// Fill out your copyright notice in the Description page of Project Settings.


#include "GPPaperCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void AGPPaperCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

void AGPPaperCharacter::OnMoveUp(float AxisValue)
{
	AddMovementInput(AxisValue * GetActorForwardVector());
}

void AGPPaperCharacter::OnMoveRight(float AxisValue)
{
	AddMovementInput(AxisValue * GetActorRightVector());
}

void AGPPaperCharacter::OnJump()
{
	Jump();
}