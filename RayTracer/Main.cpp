#include "Renderer.h"
#include "Framebuffer.h"
#include "Image.h"
#include "ImageProcess.h"
#include "Tracer.h"
#include "Scene.h"
#include "Metal.h"
#include "Lambertian.h"

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
	scene->Add(std::move(std::make_unique<Sphere>(glm::vec3{ 0, 0, -10 }, 3.0f, std::make_shared<Lambertian>(glm::vec3{ 1, 0, 0 }))));
	scene->Add(std::move(std::make_unique<Sphere>(glm::vec3{ 3, 3, -8 }, 1.0f, std::make_shared<Metal>(glm::vec3{ 0, 1, 0 }, 0.0f))));
	scene->Add(std::move(std::make_unique<Plane>(glm::vec3{ 0, -3, 0 }, glm::vec3{ 0, 1, 0 }, std::make_shared<Lambertian>(glm::vec3{ 0.5f, 0.5f, 0.5f }))));


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

		renderer->CopyBuffer(framebuffer.get());
		renderer->Present();
	}

	SDL_Quit();

	return 0;
}
