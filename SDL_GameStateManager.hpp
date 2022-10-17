#pragma once


#include "IGameStateManager.hpp" 

struct SDL_WindowEvent;

class SDL_GameStateManager:public IGameStateManager
{
	friend Singleton<SDL_GameStateManager>;

	SDL_GameStateManager() {};



	//event
	friend class SDL_EventHandeler;
	void HandelEvent(SDL_WindowEvent* winEvent);
	

public:
	virtual void Update();
	virtual void Draw();
};

typedef Singleton<SDL_GameStateManager> TheSDLGameStateManager;