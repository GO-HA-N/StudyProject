// SGameInstance.cpp


#include "Game/SGameInstance.h"
#include "Example/SPigeon.h"
#include "Example/SEagle.h"
#include "Example/SFlyable.h"
#include "JsonObjectConverter.h"
#include "UObject/SavePackage.h"

USGameInstance::USGameInstance()
{
}

void USGameInstance::Init()
{
	Super::Init();

	SpawnedPigeon = NewObject<USPigeon>();
	SpawnedPigeon->SetPigeonName(TEXT("SpawnedPigeon"));
	SpawnedPigeon->SetPigeonID(7);

	if (SpawnedPigeon->OnPigeonFlying.IsAlreadyBound(this, &ThisClass::HandlePigeonFlying) == false)
	{
		SpawnedPigeon->OnPigeonFlying.AddDynamic(this, &ThisClass::HandlePigeonFlying);
	}
	SpawnedPigeon->Fly();
}

void USGameInstance::Shutdown()
{
	Super::Shutdown();

	if (true == SpawnedPigeon->OnPigeonFlying.IsAlreadyBound(this, &ThisClass::HandlePigeonFlying))
	{
		SpawnedPigeon->OnPigeonFlying.RemoveDynamic(this, &ThisClass::HandlePigeonFlying);
	}
}

void USGameInstance::HandlePigeonFlying(const FString& InName, const int32 InID)
{
	UE_LOG(LogTemp, Log, TEXT("[%d] %s is now flying."), InID, *InName);
}
