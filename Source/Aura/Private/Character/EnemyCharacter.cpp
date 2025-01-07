// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EnemyCharacter.h"
#include"AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include"Aura/Aura.h"


AEnemyCharacter::AEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	//创建能力系统
	AblilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	//允许复制
	AblilitySystemComponent->SetIsReplicated(true);
	//迷你模式
	AblilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	//创建属性集
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");


}

void AEnemyCharacter::HighlightActor()
{
	//开启深度管道渲染
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOME_DEPTH_RED);

	//武器的深度管道渲染
	m_weapon->SetRenderCustomDepth(true);
	m_weapon->SetCustomDepthStencilValue(CUSTOME_DEPTH_RED);

}

void AEnemyCharacter::UnHighlightActor()
{
	//关闭
	GetMesh()->SetRenderCustomDepth(false);
	m_weapon->SetRenderCustomDepth(false);
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	//初始化并绑定关系
	AblilitySystemComponent->InitAbilityActorInfo(this, this);
}
