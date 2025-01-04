// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>

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

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//���������ת��Ϊ��ǿ���
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	//��Move
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);



}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	//���2ά����
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	//��ÿ�������ת
	const FRotator Rotation = GetControlRotation();

	//���ƫ����ת
	const FRotator YawRotation = FRotator(0.f, Rotation.Yaw, 0.f);

	//���ǰ�������ҵķ���
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>()) {

		
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);

	}

}


