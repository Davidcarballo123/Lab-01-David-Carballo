// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemigo.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AEnemigo::AEnemigo()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshEnemigo"));
	RootComponent = MeshEnemigo;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshEnemigoAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	if (MeshEnemigoAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshEnemigoAsset.Object);
	}

}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();

	GenerarNuevoDestino();
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Mover(DeltaTime);
}


void AEnemigo::GenerarNuevoDestino()
{
	float X = FMath::RandRange(WorldLimitesMin.X, WorldLimitesMax.X);
	float Y = FMath::RandRange(WorldLimitesMin.Y, WorldLimitesMax.Y);
	DestinoPorLlegar = FVector(X, Y, GetActorLocation().Z);
}


void AEnemigo::Mover(float DeltaTime)
{
	FVector PosActual = GetActorLocation();
	float Distancia   = FVector::Dist(PosActual, DestinoPorLlegar);

	if (Distancia <= ToleranciaLlegada)
	{
		GenerarNuevoDestino();
		return;
	}

	FVector Direccion = (DestinoPorLlegar - PosActual).GetSafeNormal();
	SetActorLocation(PosActual + Direccion * VelocidadMovimiento * DeltaTime);
}
