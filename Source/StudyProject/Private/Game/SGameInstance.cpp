// SGameInstance.cpp


#include "Game/SGameInstance.h"
#include "Kismet/KismetSystemLibrary.h"

USGameInstance::USGameInstance()
{
	UE_LOG(LogTemp, Log, TEXT("USGameInstance::USGameInstance() has been called."));
}

void USGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("USGameInstance::Init() has been called."));

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Init() has been called."));

	UWorld* World = GetWorld();
	checkf(IsValid(World) == true, TEXT("Invalid World."));
	UKismetSystemLibrary::PrintString(World, TEXT("Init() has been called."));
}

void USGameInstance::Shutdown()
{
	Super::Shutdown();

	UE_LOG(LogTemp, Log, TEXT("USGameInstance::Shutdown() has been called."));
}
