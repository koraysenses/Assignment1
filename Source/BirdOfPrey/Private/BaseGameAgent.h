// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Sound/SoundCue.h"
#include "BaseWeapon.h"
#include "BaseGameInstance.h"
#include "BaseGameAgent.generated.h"


UCLASS()
class ABaseGameAgent : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseGameAgent();

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey")
	float MoveSpeed;

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey")
	float Health;

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey")
	float Points;

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey")
	bool bCheckForOutOfBounds;

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey")
	float OutOfBoundsCheckTolerance;

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey")
	FVector TargetLocation;

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey")
	EAttachmentRule WeaponAttachRule;

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey")
	FName WeaponSocketName;

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey")
	ABaseWeapon* Weapon;

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey")
	TSubclassOf<ABaseWeapon> DefaultWeaponType;

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey")
	FSAgentInfo AgentInfo;

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey|Effects")
	UParticleSystem* DeathParticleSystem;

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey|Effects")
	UParticleSystem* HitParticleEffect;

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey|Effects")
	USoundCue* DeathSoundCue;

	UPROPERTY(BlueprintReadWrite, Category = "BirdOfPrey|Effects")
	USoundCue* HitSoundCue;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "BirdOfPrey")
	void ChangeWeaponType(ABaseWeapon* NewWeaponType);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "BirdOfPrey")
	void GetWeaponSpawnTransform(FTransform& SpawnTransform);

	UFUNCTION(BlueprintCallable, Category = "BirdOfPrey")
	void SpawnDefaultWeapon();

	UFUNCTION(BlueprintCallable, Category = "BirdOfPrey")
	void StartFire();

	UFUNCTION(BlueprintCallable, Category = "BirdOfPrey")
	void StopFire();

	UFUNCTION(BlueprintCallable, Category = "BirdOfPrey")
	virtual void TakeDamage(float Damage, float& ActualDamage);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "BirdOfPrey")
	bool IsAlive();

	UFUNCTION(BlueprintCallable, Category = "BirdOfPrey")
	void Died(AController* Killer);

	UFUNCTION(BlueprintCallable, Category = "BirdOfPrey")
	void PlayHitEffects();

	UFUNCTION(BlueprintCallable, Category = "BirdOfPrey")
	void CleanUp();

	UFUNCTION(BlueprintCallable, Category = "BirdOfPrey")
	void ApplyAgentInfo(FSAgentInfo NewAgentInfo);

	UFUNCTION(BlueprintCallable, Category = "BirdOfPrey")
	void AimAt(FVector AimTarget);

	UFUNCTION(BlueprintCallable, Category = "BirdOfPrey")
	void PlayDeathEffects();

	UFUNCTION(BlueprintCallable, Category = "BirdOfPrey")
	void CheckForOutOfBounds();

};
