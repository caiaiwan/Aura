// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"
#include"UI/Widget/AuraUserWidget.h"
#include"UI/WidgetController/OverlayWidgetController.h"


UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	
	if (!OverlayWidgetController) {
		//创建覆盖层(this为创造物划分生命周期，OverlayWidgetControllerClass为创建物的类)
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
	}

	return OverlayWidgetController;
	
}

void AAuraHUD::InitOverlay(APlayerState* PS, APlayerController* PC, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	//检查
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Init Failed!"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Init Failed!"));
	//创建
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);

	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	FWidgetControllerParams WidgetControllerParams(PS,PC,ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->setWidgetController(WidgetController);
	WidgetController->BroadcastInitalValues();

	Widget->AddToViewport();
}

