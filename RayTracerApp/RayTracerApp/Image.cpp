#include "Image.hpp"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "vendor/stb_image/stb_image.h"
#include "vendor/stb_image/stb_image_write.h"

/**
* Basic constructor. Creates a ray object that has fixed parameters.
* @param h - height of image
* @param w - widht of image
* @param s - number of samples to sampling
* @returns Image object
*/
Image::Image(int h, int w, int s)
{
	this->Height_ = h;
	this->Width_ = w;
	this->SamplesPerPixel_ = s;
	this->OutputImageData_ = std::make_shared<std::vector<unsigned char>>();
}

/**
* Function that writing image data to bmp file
* @param filename - filename of bmp file
* @param x - widht of file to save
* @param y - height of file to save
* @param comp - numbers of color channels
*/
void Image::WriteImage(char const* filename, int x, int y, int comp)
{
	stbi_write_bmp(filename, x, y, comp, this->OutputImageData_->data());
}

/**
* Function that writing image data to bmp file
* @param li - LightIntensity object to save
*/
void Image::SavePixel(LightIntensity li)
{
	this->OutputImageData_->push_back(li.R());
	this->OutputImageData_->push_back(li.G());
	this->OutputImageData_->push_back(li.B());
	this->OutputImageData_->push_back(li.A());
}
