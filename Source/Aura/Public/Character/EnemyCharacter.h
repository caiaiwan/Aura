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

	//高亮
	virtual void HighlightActor() override;

	//取消高亮
	virtual void UnHighlightActor() override;

	virtual void BeginPlay() override;

};
