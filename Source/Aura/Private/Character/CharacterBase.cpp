#include "Character/CharacterBase.h"

ACharacterBase::ACharacterBase()
{
 	PrimaryActorTick.bCanEverTick = false;

	//给骨骼网格添加WeaponHandSocket的插槽来放置武器
	m_weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	
	//将武器绑定到网格上
	m_weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	
	//武器取消碰撞
	m_weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}


UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ACharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}
