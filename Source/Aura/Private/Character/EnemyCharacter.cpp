// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EnemyCharacter.h"
#include"Aura/Aura.h"

void AEnemyCharacter::HighlightActor()
{
	//������ȹܵ���Ⱦ
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOME_DEPTH_RED);

	//��������ȹܵ���Ⱦ
	m_weapon->SetRenderCustomDepth(true);
	m_weapon->SetCustomDepthStencilValue(CUSTOME_DEPTH_RED);

}

void AEnemyCharacter::UnHighlightActor()
{
	//�ر�
	GetMesh()->SetRenderCustomDepth(false);
	m_weapon->SetRenderCustomDepth(false);
}
