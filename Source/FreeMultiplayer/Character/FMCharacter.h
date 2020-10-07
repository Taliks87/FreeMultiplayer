// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FMCharacter.generated.h"

UCLASS(config = Game)
class AFMCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AFMCharacter();

	/** Called for forwards/backward input */
	UFUNCTION(BlueprintCallable, Category = "Move")
	void MoveForward(float Value);

	/** Called for side to side input */
	UFUNCTION(BlueprintCallable, Category = "Move")
	void MoveRight(float Value);

	FORCEINLINE float GetSprintSpeed() { return SprintSpeed; }

	FORCEINLINE bool IsSprinting() { return bIsHoldingSprinting && !GetVelocity().IsZero() && FVector::DotProduct(GetActorRightVector(), GetVelocity().GetSafeNormal()); }

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
