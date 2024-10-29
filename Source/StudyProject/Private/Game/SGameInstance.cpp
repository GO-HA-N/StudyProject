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
}

void USGameInstance::Shutdown()
{
	Super::Shutdown();
}
