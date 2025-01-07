// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"


AAuraPlayerState::AAuraPlayerState()
{
	//创建能力系统
	AblilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	//允许复制
	AblilitySystemComponent->SetIsReplicated(true);
	//设置混合1模式
	AblilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	//创建属性集
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

	//传输频率
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AblilitySystemComponent;
}

UAttributeSet* AAuraPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}


