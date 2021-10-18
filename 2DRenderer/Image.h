#pragma once
#include "ColorBuffer.h"
#include <string>

using color_t = SDL_Color;

class Image
{
	friend class Framebuffer;

public:
	bool Load(const std::string& filename, uint8_t alpha = 255);
	void Flip();

private:
	ColorBuffer colorBuffer;
};
