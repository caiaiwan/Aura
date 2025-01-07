// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"


AAuraPlayerState::AAuraPlayerState()
{
	//��������ϵͳ
	AblilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	//������
	AblilitySystemComponent->SetIsReplicated(true);
	//���û��1ģʽ
	AblilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	//�������Լ�
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

	//����Ƶ��
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


