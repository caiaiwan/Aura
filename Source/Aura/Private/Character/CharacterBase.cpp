
#include "Character/CharacterBase.h"

ACharacterBase::ACharacterBase()
{
 	PrimaryActorTick.bCanEverTick = false;

	m_weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	m_weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	m_weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}
