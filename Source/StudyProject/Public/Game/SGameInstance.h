// SGameInstance.h

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h" // SUnrealObject와 다른 이유를 생각해보자. 상속받는 클래스가 다르니까
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