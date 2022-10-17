#include "SDL_TTFFont.hpp"

#include <SDL_ttf.h>
#include "SDL_ScreenHandeler.hpp"

static int initTTF = TTF_Init();

bool SDL_TTFFont::RenderFont()
{
	m_Charecters.clear();

	if (m_Texture)
		SDL_DestroyTexture(m_Texture);

	TTF_Font* font = TTF_OpenFont(m_FileName.c_str(), m_Size);

	if (!font)
	{
		printf("Faild to load FFT font: %s", TTF_GetError());
		return true;
	}

	SDL_Color color{ 0,0,0,255 };
	Uint32 rmsk = 0x000000ff;
	Uint32 gmsk = 0x0000ff00;
	Uint32 bmsk = 0x00ff0000;
	Uint32 amsk = 0xff000000;
	SDL_Surface* tenpTexture;
	tenpTexture = SDL_CreateRGBSurface(0, 512, 512, 32, rmsk, gmsk, bmsk, amsk);

	int x = 0;
	int y = 0;

	for (int i = 33; i < 126; i++)
	{
		char letter[2] = { (char)i, '\0' };
		Rectangle letterRect;

		//Measure letter size;
		TTF_SizeText(font, letter, &letterRect.Width, &letterRect.Height);

		if (x + letterRect.Width > tenpTexture->w)
		{
			x = 0;
			y += letterRect.Height;
		}

		letterRect.X = x;
		letterRect.Y = y;
		x += letterRect.Width;

		SDL_Surface* letterTexture = TTF_RenderText_Solid(font, letter, color);

		SDL_Rect dest
		{
			letterRect.X,
			letterRect.Y,
			letterRect.Width,
			letterRect.Height

		};
		SDL_BlitSurface(letterTexture, NULL, tenpTexture, &dest);

		SDL_FreeSurface(letterTexture);

		m_Charecters[(char)i] = letterRect;
	}

	m_Texture = SDL_CreateTextureFromSurface(TheSDL_ScreenHandeler::Pointer()->GetRenderer(), tenpTexture);
	m_TextureSize.Width = 512;
	m_TextureSize.Height = 512;
	SDL_FreeSurface(tenpTexture);

	return false;
}

void SDL_TTFFont::DrawString(std::string string, Vector2 location)
{
	Vector2F loc = location;
	for (unsigned int i = 0; i < string.size(); i++)
	{
		RectangleF letter = m_Charecters[string[i]];
		SDL_Rect source
		{
			(int)letter.X,
			(int)letter.Y,
			(int)letter.Width,
			(int)letter.Height
		};

		SDL_Rect destination;
		destination.x = (int)loc.X;
		destination.y = (int)loc.Y;
		destination.w = source.w;
		destination.h = source.h;

		SDL_RenderCopy(TheSDL_ScreenHandeler::Pointer()->GetRenderer(),
			m_Texture,
			&source,
			&destination);

		loc.X += letter.Width;
	}
}

void SDL_TTFFont::SetSize(int size)
{
	m_Size = size;
	RenderFont();
}

bool SDL_TTFFont::Load(std::string TTFfont)
{
	m_FileName = TTFfont;
	m_Size = 12;

	return RenderFont();
}