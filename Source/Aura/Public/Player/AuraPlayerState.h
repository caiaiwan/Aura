// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include"AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AAuraPlayerState();

	//��д�ӿڵķ���
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//���getter
	UAttributeSet* GetAttributeSet() const;

	//����ϵͳ
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AblilitySystemComponent;

	//���Լ�
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
