#include "Renderer.h"
#include "Framebuffer.h"
#include <iostream>
#include <SDL.h>

int main(int, char**)
{
	const int WIDTH = 800;
	const int HEIGHT = 600;

	std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>();
	renderer->Initialize(WIDTH, HEIGHT);

	std::unique_ptr<Framebuffer> framebuffer = std::make_unique<Framebuffer>(renderer.get(), renderer->width, renderer->height);
	
	bool quit = false;
	SDL_Event event;
	while (!quit)
	{
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}

		framebuffer->Clear({0,0,0,0});
		
		/*
		for (int i = 0; i < 50; i++)
		{
			framebuffer->DrawRect(rand() % framebuffer->width, rand() % framebuffer->height, 25, 25, { 0, 255, 0, 255 });
		}
		*/

		/*for (int i = 0; i < 60; i++)
		{
			framebuffer->DrawLine(framebuffer->width >> 1, framebuffer->height >> 1, rand() % framebuffer->width, rand() % framebuffer->height, {0, 0, 255, 255 });
		}

		framebuffer->DrawTriangle(20, 50, 30, 50, 20, 30, {255,0,0,255});*/

		//framebuffer->DrawSimpleCurve(200, 200, 500, 500, 20, {255, 255, 255, 255});
		framebuffer->DrawQuadraticCurve(200, 200, 500, 500, 300, 300, 20, {255, 255, 255, 255});

		framebuffer->Update();

		renderer->CopyBuffer(framebuffer.get());
		renderer->Present();
	}

	SDL_Quit();

	return 0;
}
