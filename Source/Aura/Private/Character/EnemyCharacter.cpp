// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EnemyCharacter.h"
#include"AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include"Aura/Aura.h"


AEnemyCharacter::AEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	//��������ϵͳ
	AblilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	//������
	AblilitySystemComponent->SetIsReplicated(true);
	//����ģʽ
	AblilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	//�������Լ�
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");


}

void AEnemyCharacter::HighlightActor()
{
	//������ȹܵ���Ⱦ
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOME_DEPTH_RED);

	//��������ȹܵ���Ⱦ
	m_weapon->SetRenderCustomDepth(true);
	m_weapon->SetCustomDepthStencilValue(CUSTOME_DEPTH_RED);

}

void AEnemyCharacter::UnHighlightActor()
{
	//�ر�
	GetMesh()->SetRenderCustomDepth(false);
	m_weapon->SetRenderCustomDepth(false);
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	//��ʼ�����󶨹�ϵ
	AblilitySystemComponent->InitAbilityActorInfo(this, this);
}
