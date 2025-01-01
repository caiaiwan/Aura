// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include <EnhancedInputSubsystems.h>

AAuraPlayerController::AAuraPlayerController()
{
	//�����ݸ��Ƶ����пͻ���
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//����Ƿ���Ч
	check(AuraContext);

	//����ұ��ػ�ȡ��ǿ������ϵͳ
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	check(Subsystem);
	
	//������ӳ����ӵ���ϵͳ�����ȼ�Ϊ0
	Subsystem->AddMappingContext(AuraContext, 0);

	//��ʾ�����
	bShowMouseCursor = true;

	//���ΪϵͳĬ�ϵĹ��
	DefaultMouseCursor = EMouseCursor::Default;

	//��ģʽ������Ϸ���û�����ͬʱ��������
	FInputModeGameAndUI InputModeData;

	//��������굽��Ϸ������
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	//�������ʱ��������
	InputModeData.SetHideCursorDuringCapture(false);

	//���ģʽ
	SetInputMode(InputModeData);


}
