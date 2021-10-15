#include "Image.h"
#include <fstream>

Image::~Image()
{
	delete[] buffer;
}

bool Image::Load(const std::string& filename, uint8_t alpha)
{
	std::ifstream stream(filename, std::ios::binary);
	if (stream.fail())
	{
		std::cout << "Error: Cannot open file: " << filename << std::endl;
		return false;
	}

	uint8_t header[54];
	stream.read((char*)header, 54);

	uint16_t id = *((uint16_t*)(header));
	if (id != 'MB')
	{
		std::cout << "Error: Invalid file format: " << filename << std::endl;
		return false;
	}
	
	width = *((int*)(&header[18]));
	height = *((int*)(&header[22]));
	
	int pitch = width * sizeof(color_t);

	buffer = new uint8_t[width * pitch];

	uint16_t bitsPerPixel = *((uint16_t*)(&header[28]));

	uint16_t bytesPerPixel = bitsPerPixel / 8;

	size_t size = width * height * bytesPerPixel;

	uint8_t* data = new uint8_t[size];

	stream.read((char*)data, size);

	for (int i = 0; i < width * height; i++)
	{
		color_t color;

		// colors in bmp data are stored (BGR)
		int index = i * bytesPerPixel;
		color.b = data[index];
		color.g = data[index + 1];
		color.r = data[index + 2];
		color.a = alpha;

		((color_t*)(buffer))[i] = color;
	}

	delete[] data;

	stream.close();

	return true;
}

void Image::Flip()
{
	// set the pitch (width * number of bytes per pixel)
	int pitch = width * sizeof(color_t);

	// create temporary line to store data
	uint8_t* temp = new uint8_t[pitch];

	for (int i = 0; i < height / 2; i++)
	{
		uint8_t* line1 = &((buffer)[i * pitch]);
		uint8_t* line2 = &((buffer)[((height - 1) - i) * pitch]);
		memcpy(temp, line1, pitch);
		memcpy(line1, line2, pitch);
		memcpy(line2, temp, pitch);
	}
	delete[] temp;
}

