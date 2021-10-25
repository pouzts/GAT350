#include "Renderer.h"
#include "Framebuffer.h"
#include "Image.h"
#include "ImageProcess.h"
#include "Tracer.h"
#include "Scene.h"

#include <SDL.h>
#include <iostream>

int main(int, char**)
{
	const int WIDTH = 800;
	const int HEIGHT = 600;

	std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>();
	renderer->Initialize(WIDTH, HEIGHT);

	std::unique_ptr<Framebuffer> framebuffer = std::make_unique<Framebuffer>(renderer.get(), renderer->width, renderer->height);

	// ray tracer
	std::unique_ptr<Tracer> tracer = std::make_unique<Tracer>();

	// scene
	std::unique_ptr<Scene> scene = std::make_unique<Scene>();
	std::unique_ptr<Sphere> sphere = std::make_unique<Sphere>(glm::vec3{ 0, 0, -10 }, 3.0f);
	scene->Add(std::move(sphere));

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

		tracer->Trace(framebuffer->colorBuffer, scene.get());

		framebuffer->Update();

		renderer->CopyBuffer(framebuffer.get());
		renderer->Present();
	}

	SDL_Quit();

	return 0;
}
