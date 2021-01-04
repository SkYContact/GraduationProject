// Copyright Epic Games, Inc. All Rights Reserved.

#include "LensDistortionBlueprintLibrary.h"



UGPShaderBlueprintLibrary::UGPShaderBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{ }


// static
void UGPShaderBlueprintLibrary::GetUndistortOverscanFactor(
	const FGPShaderCameraModel& CameraModel,
	float DistortedHorizontalFOV,
	float DistortedAspectRatio,
	float& UndistortOverscanFactor)
{
	UndistortOverscanFactor = CameraModel.GetUndistortOverscanFactor(DistortedHorizontalFOV, DistortedAspectRatio);
}


// static
void UGPShaderBlueprintLibrary::DrawUVDisplacementToRenderTarget(
	const UObject* WorldContextObject,
	const FGPShaderCameraModel& CameraModel,
	float DistortedHorizontalFOV,
	float DistortedAspectRatio,
	float UndistortOverscanFactor,
	class UTextureRenderTarget2D* OutputRenderTarget,
	float OutputMultiply,
	float OutputAdd)
{
	CameraModel.DrawUVDisplacementToRenderTarget(
		WorldContextObject->GetWorld(),
		DistortedHorizontalFOV, DistortedAspectRatio,
		UndistortOverscanFactor, OutputRenderTarget,
		OutputMultiply, OutputAdd);
}
