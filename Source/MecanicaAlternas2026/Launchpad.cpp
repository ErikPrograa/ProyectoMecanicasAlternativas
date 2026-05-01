#include "LaunchPad.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"

ALaunchPad::ALaunchPad()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(RootComponent);
	
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ALaunchPad::OnOverlapBegin);
}

void ALaunchPad::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
								UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
								bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* Character = Cast<ACharacter>(OtherActor);
    
	if (Character)
	{
		Character->LaunchCharacter(FVector(0.0f, 0.0f, LaunchStrength), true, true);
	}
}