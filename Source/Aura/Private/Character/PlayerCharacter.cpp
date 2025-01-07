// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"
#include"GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"
#include "AbilitySystemComponent.h"


APlayerCharacter::APlayerCharacter()
{
	//��ɫ����������ת
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//��ת������
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);

	//���ƽ�ɫֻ����һ��ƽ�����ƶ�
	GetCharacterMovement()->bConstrainToPlane = true;

	//��ɫλ�úͳ���̶���һ��ƽ��
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	//��ɫ�������������ת
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;


}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//����������ʼ��Ability Actor
	InitAbilityActorInfo();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	//���ͻ��˳�ʼ��Ability Actor
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
