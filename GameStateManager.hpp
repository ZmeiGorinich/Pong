#pragma once

#include "Singleton.hpp"
#include "IGameState.hpp"

class GameStateManager :public Uncopyable
{
public:
	IGameState* GetState() { return m_CurrentState; }

	void SetState(IGameState* gs);

	virtual void Run();

	virtual void Update();

	virtual void Draw();

protected:
	IGameState* m_CurrentState = nullptr;

	GameStateManager() {}
	friend Singleton<GameStateManager>;
};

typedef  Singleton<GameStateManager> TheGameStateManager;