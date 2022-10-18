#include <SDL.h>
#include "SDL_Engine/SDL_ScreenHandeler.hpp"
#include "SDL_Engine/SDL_GameStateManager.hpp"

#include "Game/Game.hpp"
#include "DEFINITIONS.hpp"


int main(int argc, char* argv[])
{
    TheSDL_ScreenHandeler::Pointer()->Initialize("PongGame", Size(WINDOW_WIDTH, WINDOW_HEIGHT));
    TheSDL_ScreenHandeler::Pointer()->SetBackBufferColor(SDL_Color{ 100, 149, 237, 255 });
    TheSDLGameStateManager::Pointer()->SetState(TheGameState::Pointer());
    TheSDLGameStateManager::Pointer()->Run();

    return 0;
}