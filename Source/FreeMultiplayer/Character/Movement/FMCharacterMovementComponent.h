// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "FMCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class FREEMULTIPLAYER_API UFMCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:	
	float GetMaxSpeed() const override;	
};
