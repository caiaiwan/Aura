
#pragma once

#include "CoreMinimal.h"
#include"AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class AURA_API ACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACharacterBase();

	//重写接口的方法
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//添加getter
	UAttributeSet* GetAttributeSet() const;


	//武器插槽
	UPROPERTY(EditAnywhere,Category="Combat")
	TObjectPtr<USkeletalMeshComponent> m_weapon;

	//能力系统
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AblilitySystemComponent;

	//属性集
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

protected:

	virtual void BeginPlay() override;
};
