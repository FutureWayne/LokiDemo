// Copyright Ludens Studio. All Rights Reserved.

#pragma once

#include "Engine/LocalPlayer.h"
#include "Teams/ArenaTeamAgentInterface.h"
#include "ArenaLocalPlayer.generated.h"

/**
 * 
 */
UCLASS()
class ARENA_API UArenaLocalPlayer : public ULocalPlayer, public IArenaTeamAgentInterface
{
	GENERATED_BODY()

public:
	UArenaLocalPlayer();
	
	//~ Begin IArenaTeamAgentInterface Interface
	virtual void SetGenericTeamId(const FGenericTeamId& TeamID) override;
	virtual FGenericTeamId GetGenericTeamId() const override;
	virtual FOnArenaTeamIndexChangedDelegate* GetOnTeamIndexChangedDelegate() override;
	//~ End IArenaTeamAgentInterface Interface

private:
	UPROPERTY()
    FOnArenaTeamIndexChangedDelegate OnTeamChangedDelegate;
};
