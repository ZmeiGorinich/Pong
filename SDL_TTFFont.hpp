#pragma once

#include "SDL_Image.hpp"
#include "IFont.hpp"

class SDL_TTFFont : public IFont, protected SDL_Image
{
	std::string m_FileName;

	bool RenderFont();

public:
	virtual void DrawString(std::string string, Vector2 location) override;
	void SetSize(int size);
	bool Load(std::string TTFfont);
};
