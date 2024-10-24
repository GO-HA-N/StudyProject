// SGameInstance.cpp


#include "Game/SGameInstance.h"
#include "Example/SPigeon.h"
#include "Example/SEagle.h"
#include "Example/SFlyable.h"

USGameInstance::USGameInstance()
{
}

PRAGMA_DISABLE_OPTIMIZATION
void USGameInstance::Init()
{
	Super::Init();

	USPigeon* Pigeon1 = NewObject<USPigeon>();
	if (IsValid(Pigeon1) == true)
	{
		Pigeon1->Fly();
	}

	USEagle* Eagle1 = NewObject<USEagle>();
	if (IsValid(Eagle1) == true)
	{
		Eagle1->Fly();
	}

	TArray<ISFlyable*> Birds;
	Birds.Reserve(10);

	if (Pigeon1->GetClass()->ImplementsInterface(USFlyable::StaticClass()) == true)
	{
		ISFlyable* Bird1 = Cast<ISFlyable>(Pigeon1);
		Birds.Emplace(Bird1);
	}

	if (Eagle1->GetClass()->ImplementsInterface(USFlyable::StaticClass()) == true)
	{
		ISFlyable* Bird2 = Cast<ISFlyable>(Eagle1);
		Birds.Emplace(Bird2);
	}

	for (auto Bird : Birds)
	{
		Bird->Fly();
	}
}
PRAGMA_ENABLE_OPTIMIZATION

void USGameInstance::Shutdown()
{
	Super::Shutdown();
}
