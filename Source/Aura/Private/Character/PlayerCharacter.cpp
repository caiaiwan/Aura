// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"
#include"GameFramework/CharacterMovementComponent.h"

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
