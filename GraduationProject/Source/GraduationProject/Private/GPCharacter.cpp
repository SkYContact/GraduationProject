// Fill out your copyright notice in the Description page of Project Settings.


#include "GPCharacter.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AGPCharacter::AGPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector AGPCharacter::GetIKFootLocation(float FootIKTraceDistance, FName IKFootSocketName, FName IKRootSocketName)
{
	USkeletalMeshComponent* SkeletalMeshComponent = GetMesh();
	check(SkeletalMeshComponent);
	const FVector FootLocation = SkeletalMeshComponent->GetSocketLocation(IKFootSocketName);
	const FVector RootLocation = SkeletalMeshComponent->GetSocketLocation(IKRootSocketName);
	FVector TraceStartLocation = FootLocation;
	TraceStartLocation.Z = GetActorLocation().Z;
	FVector TraceEndLocation = TraceStartLocation;
	TraceEndLocation.Z -= FootIKTraceDistance;
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStartLocation, TraceEndLocation, GetCapsuleComponent()->GetCollisionObjectType(), Params);
	FVector OutFootLocation = TraceEndLocation;
	if (HitResult.bBlockingHit)
	{
		OutFootLocation = HitResult.Location;
	}
	return OutFootLocation;
}

// Called to bind functionality to input
void AGPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

