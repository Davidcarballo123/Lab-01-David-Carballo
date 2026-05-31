// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

UCLASS()
class NAVESUSFX_012026_API AEnemigo : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemigo();

	// Componente visual del enemigo
	UStaticMeshComponent* MeshEnemigo;

	float VelocidadMovimiento = 500.0f;

	float ToleranciaLlegada = 50.0f;

	FVector WorldLimitesMin = FVector(-1000.0f, -1000.0f, 0.0f);

	FVector WorldLimitesMax = FVector(1000.0f, 1000.0f, 0.0f);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	FVector DestinoPorLlegar;

	void GenerarNuevoDestino();
	void Mover(float DeltaTime);
};
