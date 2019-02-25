// Fill out your copyright notice in the Description page of Project Settings.

#include "PZ_1GameModeBase.h"
#include <OutputDeviceNull.h>
#include <UnrealType.h>


void APZ_1GameModeBase::BeginPlay()
{
	FOutputDeviceNull ar;
	this->CallFunctionByNameWithArguments(TEXT("ETest"), ar, this, true);
	UFloatProperty* FloatProp = FindField<UFloatProperty>(this->GetClass(), TEXT("f_Test"));

	if (FloatProp != nullptr)
	{
		float FloatValue = FloatProp->GetPropertyValue_InContainer(this);
		UE_LOG(LogTemp, Warning, TEXT("Float value = %f"), FloatValue);

		FloatProp->SetPropertyValue_InContainer(this, 0.2332f);

		FloatValue = FloatProp->GetPropertyValue_InContainer(this);
		UE_LOG(LogTemp, Warning, TEXT("New float value = %f"), FloatValue);
	}	
}