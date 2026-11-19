// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "move.h"
#include "Components/BoxComponent.h"
#include "TriggerComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ESCAPEROOMVH_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	UTriggerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Trigger(bool triggerValue);
	
	UPROPERTY(EditAnywhere)
	bool isPreasurePlate = false;
	UPROPERTY(VisibleAnywhere)
	bool isTriggered = false;
	UPROPERTY(EditAnywhere)
	AActor* moveActor;

	UMove* moveComponent;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* overlapComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* overlapComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex);
};
