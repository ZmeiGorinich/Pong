#pragma once
#include <string>
#include "SDL.h"
#include "Singleton.hpp"
#include "Size.hpp"
class SDL_ScreenHandeler:public Uncopyable
{
	friend class Singleton<SDL_ScreenHandeler>;
	SDL_ScreenHandeler() {};

	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;

	SDL_Color m_BackBufferColor;
public:
	bool Initialize(std::string,Size windowSize);
	void SetBackBufferColor(SDL_Color color);
	void Flip();

	SDL_Renderer* GetRenderer();

	~SDL_ScreenHandeler();

};

typedef Singleton<SDL_ScreenHandeler> TheSDL_ScreenHandeler;