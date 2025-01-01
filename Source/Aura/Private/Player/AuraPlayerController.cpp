// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include <EnhancedInputSubsystems.h>

AAuraPlayerController::AAuraPlayerController()
{
	//将内容复制到所有客户端
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//检查是否有效
	check(AuraContext);

	//从玩家本地获取增强输入子系统
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	check(Subsystem);
	
	//将输入映射添加到子系统，优先级为0
	Subsystem->AddMappingContext(AuraContext, 0);

	//显示鼠标光标
	bShowMouseCursor = true;

	//光标为系统默认的光标
	DefaultMouseCursor = EMouseCursor::Default;

	//该模式用于游戏和用户界面同时接受输入
	FInputModeGameAndUI InputModeData;

	//不锁定鼠标到游戏窗口内
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	//捕获鼠标时，不隐藏
	InputModeData.SetHideCursorDuringCapture(false);

	//添加模式
	SetInputMode(InputModeData);


}
