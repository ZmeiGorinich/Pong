#include "SDL_Image.hpp"

#include <SDL.h>
#include <SDL_image.h>

#include "SDL_ScreenHandeler.hpp"

bool SDL_Image::Load(const std::string& File)
{
    // load our image
    m_Texture = IMG_LoadTexture(TheSDL_ScreenHandeler::Pointer()->GetRenderer(), File.c_str());
    if (!m_Texture)
    {
        printf("SDL_image load failed: %s\n", SDL_GetError());
        return true;
    }

    // get the width and height of the texture
    SDL_QueryTexture(m_Texture, NULL, NULL, &m_TextureSize.Width, &m_TextureSize.Height);

    return false;
}

void SDL_Image::Draw(const Vector2& Location)
{
    SDL_Rect destination;
    destination.x = Location.X;
    destination.y = Location.Y;
    destination.w = m_TextureSize.Width;
    destination.h = m_TextureSize.Height;

    SDL_RenderCopy(TheSDL_ScreenHandeler::Pointer()->GetRenderer(), m_Texture, NULL, &destination);
}

SDL_Image::~SDL_Image() {}