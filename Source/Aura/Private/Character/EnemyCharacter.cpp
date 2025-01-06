// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EnemyCharacter.h"
#include"Aura/Aura.h"

void AEnemyCharacter::HighlightActor()
{
	//开启深度管道渲染
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOME_DEPTH_RED);

	//武器的深度管道渲染
	m_weapon->SetRenderCustomDepth(true);
	m_weapon->SetCustomDepthStencilValue(CUSTOME_DEPTH_RED);

}

void AEnemyCharacter::UnHighlightActor()
{
	//关闭
	GetMesh()->SetRenderCustomDepth(false);
	m_weapon->SetRenderCustomDepth(false);
}
