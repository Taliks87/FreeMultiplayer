// Fill out your copyright notice in the Description page of Project Settings.


#include "FMCharacterMovementComponent.h"
#include "../FMCharacter.h"

float UFMCharacterMovementComponent::GetMaxSpeed() const
{
	AFMCharacter* FMCharacter = StaticCast<AFMCharacter*>(GetCharacterOwner());
	if (FMCharacter->IsSprinting())
	{
		return FMCharacter->GetSprintSpeed();
	}
	return Super::GetMaxSpeed();
}