
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

	//��д�ӿڵķ���
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//���getter
	UAttributeSet* GetAttributeSet() const;


	//�������
	UPROPERTY(EditAnywhere,Category="Combat")
	TObjectPtr<USkeletalMeshComponent> m_weapon;

	//����ϵͳ
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AblilitySystemComponent;

	//���Լ�
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

protected:

	virtual void BeginPlay() override;
};
