// Copyright Ludens Studio. All Rights Reserved.


#include "GameState/ArenaGameState.h"

#include "AbilitySystem/ArenaAbilitySystemComponent.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "Messages/ArenaVerbMessage.h"


AArenaGameState::AArenaGameState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = ObjectInitializer.CreateDefaultSubobject<UArenaAbilitySystemComponent>(this, TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

void AArenaGameState::PreInitializeComponents()
{
	Super::PreInitializeComponents();
}

void AArenaGameState::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(/*Owner=*/ this, /*Avatar=*/ this);
}


UAbilitySystemComponent* AArenaGameState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AArenaGameState::MulticastMessageToClients_Implementation(const FArenaVerbMessage Message)
{
	if (GetNetMode() == NM_Client)
	{
		UGameplayMessageSubsystem::Get(this).BroadcastMessage(Message.Verb, Message);
	}
}

void AArenaGameState::MulticastReliableMessageToClients_Implementation(const FArenaVerbMessage Message)
{
	MulticastMessageToClients_Implementation(Message);
}

void AArenaGameState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AArenaGameState::AddPlayerState(APlayerState* PlayerState)
{
	Super::AddPlayerState(PlayerState);
}

void AArenaGameState::RemovePlayerState(APlayerState* PlayerState)
{
	Super::RemovePlayerState(PlayerState);
}

void AArenaGameState::SeamlessTravelTransitionCheckpoint(bool bToTransitionMap)
{
	Super::SeamlessTravelTransitionCheckpoint(bToTransitionMap);
}

