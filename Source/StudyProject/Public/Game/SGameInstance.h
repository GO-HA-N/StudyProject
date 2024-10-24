// SGameInstance.h

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h" // SUnrealObject�� �ٸ� ������ �����غ���. ��ӹ޴� Ŭ������ �ٸ��ϱ�
#include "SGameInstance.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API USGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	USGameInstance();

	virtual void Init() override;

	virtual void Shutdown() override;

protected:
	UPROPERTY()
	FString Name;

};