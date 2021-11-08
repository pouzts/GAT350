#pragma once
#include "ColorBuffer.h"
#include "Camera.h"

class Scene;

class Tracer
{
public:
	void Trace(const ColorBuffer& colorBuffer, Scene* scene, Camera* camera);
public:
	int samples{500};
	int depth{ 30 };
};