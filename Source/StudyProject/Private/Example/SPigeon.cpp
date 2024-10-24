// SPigeon.cpp


#include "Example/SPigeon.h"

USPigeon::USPigeon()
{
	Name = TEXT("Pigeon");
}

void USPigeon::Fly()
{
	UE_LOG(LogTemp, Log, TEXT("%s is now flying."), *Name);

	OnPigeonFlying.Broadcast(Name, ID);
}

void USPigeon::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	Ar << Name;
	Ar << ID;
}
