#pragma once
#include "ColorBuffer.h"

namespace ImageProcess
{
	void Invert(const ColorBuffer& colorBuffer);
	void Monochrome(const ColorBuffer& colorBuffer);
	void Noise(const ColorBuffer& colorBuffer, uint8_t noise);
	void Brightness(const ColorBuffer& colorBuffer, int16_t brightness);
	void ColorBalance(const ColorBuffer& colorBuffer, int16_t ro, int16_t go, int16_t bo);
	void Threshold(const ColorBuffer& colorBuffer, uint8_t threshold);
	void BoxBlur(const ColorBuffer& colorBuffer);
	void GaussianBlur(const ColorBuffer& colorBuffer);
	void Sharpen(const ColorBuffer& colorBuffer);
	void Edge(const ColorBuffer& colorBuffer, uint8_t threshold);
}