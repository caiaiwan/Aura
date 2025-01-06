// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"
#include"GameFramework/CharacterMovementComponent.h"

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
