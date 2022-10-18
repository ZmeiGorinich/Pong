#include "SDL_EventHandeler.hpp"

#include <SDL.h>
#include "SDL_GameStateManager.hpp"
#include "../Input/Keyboard.hpp"

SDL_EventHandeler::SDL_EventHandeler() = default;

void SDL_EventHandeler::PoolEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_WINDOWEVENT: TheSDLGameStateManager::Pointer()->HandelEvent(&event.window);
            case SDL_KEYUP:;
            case SDL_KEYDOWN: Keyboard::HandelEvent(&event.key); break;
        }
    }
}
