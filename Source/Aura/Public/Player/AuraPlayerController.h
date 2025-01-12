// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class IEnemyInterface;
struct FInputActionValue;

UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPlayerController();

	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	//重写输入主键
	virtual void SetupInputComponent() override;
	
private:

	//输入映射
	UPROPERTY(EditAnywhere , Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	//输入动作
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	//移动函数
	void Move(const FInputActionValue& InputActionValue);

	//光标追踪敌人
	void CursorTrace();

	//追踪的敌人
	TObjectPtr<IEnemyInterface> ThisActor;
	TObjectPtr<IEnemyInterface> LastActor;

};
