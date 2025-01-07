// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "EnemyCharacter.generated.h"


/**
 * 
 */
UCLASS()
class AURA_API AEnemyCharacter : public ACharacterBase,public IEnemyInterface
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

	//����
	virtual void HighlightActor() override;

	//ȡ������
	virtual void UnHighlightActor() override;

	virtual void BeginPlay() override;

};
