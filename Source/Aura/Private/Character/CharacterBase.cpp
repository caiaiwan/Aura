
#include "Character/CharacterBase.h"

ACharacterBase::ACharacterBase()
{
 	PrimaryActorTick.bCanEverTick = false;

	//�������������WeaponHandSocket�Ĳ������������
	m_weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	m_weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	//����ȡ����ײ
	m_weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}


UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AblilitySystemComponent;
}

UAttributeSet* ACharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}
