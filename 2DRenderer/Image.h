#pragma once
#include "SDL.h"
#include <iostream>

using color_t = SDL_Color;

class Image
{
	friend class Framebuffer;

public:
	~Image();
	bool Load(const std::string& filename, uint8_t alpha = 255);
	void Flip();

private:
	uint8_t* buffer;
	int height = 0;
	int width = 0;
};
