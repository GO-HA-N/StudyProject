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

	UFUNCTION()
	void HandlePigeonFlying(const FString& InName, const int32 InID);

protected:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	TObjectPtr<class USPigeon> SpawnedPigeon;

};