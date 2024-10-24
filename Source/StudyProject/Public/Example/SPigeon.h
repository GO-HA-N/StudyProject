// SPigeon.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SFlyable.h"
#include "SPigeon.generated.h"

USTRUCT()
struct FPigeonData
{
	GENERATED_BODY()
	
public:
	FPigeonData()
	{
	}

	FPigeonData(const FString& InName, int32 InID)
		: Name(InName), ID(InID)
	{
	}

	friend FArchive& operator<<(FArchive& InArchive, FPigeonData& InPigeonData)
	{
		InArchive << InPigeonData.Name;
		InArchive << InPigeonData.ID;
		return InArchive;
	}

public:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	int32 ID;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPigeonFlying, const FString&, InName, const int32, InID);

/**
 *
 */
UCLASS()
class STUDYPROJECT_API USPigeon : public UObject, public ISFlyable
{
	GENERATED_BODY()

public:
	USPigeon();

	virtual void Fly() override;

	const FString& GetPigeonName() const { return Name; }
	void SetPigeonName(const FString& InName) { Name = InName; }

	int32 GetPigeonID() const { return ID; }
	void SetPigeonID(const int32& InID) { ID = InID; }

	virtual void Serialize(FArchive& Ar) override;

public:
	FOnPigeonFlying OnPigeonFlying;

private:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	int32 ID;
};