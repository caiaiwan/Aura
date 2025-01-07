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

	//重写接口的方法
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//添加getter
	UAttributeSet* GetAttributeSet() const;

	//能力系统
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AblilitySystemComponent;

	//属性集
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
