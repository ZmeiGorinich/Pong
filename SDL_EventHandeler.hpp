#pragma once


#include "Singleton.hpp"

class SDL_EventHandeler :public Uncopyable
{
	friend Singleton<SDL_EventHandeler>;

	SDL_EventHandeler() {}


public:
	void PoolEvents();
};

typedef Singleton<SDL_EventHandeler> TheSDLEventHandeler;