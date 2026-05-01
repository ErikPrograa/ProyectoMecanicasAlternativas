#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaunchPad.generated.h"

UCLASS()
class MECANICAALTERNAS2026_API ALaunchPad : public AActor
{
	GENERATED_BODY()
    
public:    
	ALaunchPad();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UBoxComponent* CollisionBox;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UStaticMeshComponent* MeshComp;
	
	UPROPERTY(EditAnywhere, Category = "Fall Guys Mechanic")
	float LaunchStrength = 1500.0f;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
						bool bFromSweep, const FHitResult& SweepResult);
};