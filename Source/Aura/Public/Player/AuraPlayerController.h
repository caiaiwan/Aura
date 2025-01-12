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

	//��д��������
	virtual void SetupInputComponent() override;
	
private:

	//����ӳ��
	UPROPERTY(EditAnywhere , Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	//���붯��
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	//�ƶ�����
	void Move(const FInputActionValue& InputActionValue);

	//���׷�ٵ���
	void CursorTrace();

	//׷�ٵĵ���
	TObjectPtr<IEnemyInterface> ThisActor;
	TObjectPtr<IEnemyInterface> LastActor;

};
