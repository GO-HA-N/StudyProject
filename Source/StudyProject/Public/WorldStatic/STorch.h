// STorch.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STorch.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UPointLightComponent;
class UParticleSystemComponent;

UCLASS()
class STUDYPROJECT_API ASTorch : public AActor
{
    GENERATED_BODY()
    
public:
    ASTorch();

    virtual void BeginPlay() override;

    virtual void Tick(float DeltaSeconds) override;

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ASTorch", meta = (AllowPrivateAccess))
    TObjectPtr<UBoxComponent> BoxComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ASTorch", meta = (AllowPrivateAccess))
    TObjectPtr<UStaticMeshComponent> BodyStaticMeshComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ASTorch", meta = (AllowPrivateAccess))
    TObjectPtr<UPointLightComponent> PointLightComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ASTorch", meta = (AllowPrivateAccess))
    TObjectPtr<UParticleSystemComponent> ParticleSystemComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ASTorch", meta = (AllowPrivateAccess))
    int32 ID;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ASTorch", Meta = (AllowPrivateAccess))
    float RotationSpeed;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ASTorch", meta = (AllowPrivateAccess))
    TObjectPtr<class URotatingMovementComponent> RotatingMovementComponent;
};