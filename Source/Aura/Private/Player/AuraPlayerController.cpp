// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include"Interaction/EnemyInterface.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AAuraPlayerController::AAuraPlayerController()
{
	//将内容复制到所有客户端
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::CursorTrace()
{
	//获得光标的选择物
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);

	//如果没选择到就结束
	if (!CursorHit.bBlockingHit) return;

	
	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	
	/*对于选择的Actor一共有几种情况
	* 1.Last和This都为空：不做
	* 2.Last为空，This不为空：This高亮
	* 3.Last不为空，This为空：取消Last高亮
	* 4.Last和This都不为空：
	*   a.Last==This: 不做
	*	b.Last!=This: 取消Last高亮，This高亮
	*/

	//Last为空
	if (!LastActor) {
		
		if (!ThisActor) {
			//This为空
		}
		else {
			//This不为空
			ThisActor->HighlightActor();
		}
	}
	else {
		//Last不为空
		if (!ThisActor) {
			//This为空
			LastActor->UnHighlightActor();
		}
		else {
			//This不为空
			if (LastActor != ThisActor) {
				//This!=Last
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else {
				//This==Last
			}
		}
	}



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

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//将输入组件转换为增强组件
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	//绑定Move
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);



}

//移动
void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	//获得2维向量
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	//获得控制器旋转
	const FRotator Rotation = GetControlRotation();

	//获得偏航旋转
	const FRotator YawRotation = FRotator(0.f, Rotation.Yaw, 0.f);

	//获得前进和向右的方向
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>()) {

		
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);

	}

}




