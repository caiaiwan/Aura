// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"
#include"GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"
#include "AbilitySystemComponent.h"


APlayerCharacter::APlayerCharacter()
{
	//角色朝面向方向旋转
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//旋转的速率
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);

	//限制角色只能在一个平面内移动
	GetCharacterMovement()->bConstrainToPlane = true;

	//角色位置和朝向固定在一个平面
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	//角色不跟随控制器旋转
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;


}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//给服务器初始化Ability Actor
	InitAbilityActorInfo();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	//给客户端初始化Ability Actor
	InitAbilityActorInfo();
}

void APlayerCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	AblilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();
}
