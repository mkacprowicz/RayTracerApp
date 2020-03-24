#include "Image.hpp"

#include "vendor/stb_image/stb_image_write.h"

Image::Image(int h, int w, int s)
{
	this->Height_ = h;
	this->Width_ = w;
	this->SamplesPerPixel_ = s;
}

void Image::WriteImage(char const* filename, int x, int y, int comp, const void* data)
{
	stbi_write_bmp(filename, x, y, comp, data);
}