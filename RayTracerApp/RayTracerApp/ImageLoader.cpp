#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "ImageLoader.hpp"

#include <iostream>


    unsigned char* ImageMisc::LoadPictureData(const char* filename, int* x, int* y, int* n)
    {
    	//auto data = stbi_load(filename, x, y, n, 4);
        //return std::vector<unsigned char>(data, data + (*x * *y));
    	return stbi_load(filename, x, y, n, 4);
    }


    void ImageMisc::GetPixel(stbi_uc* image, size_t imageWidth, size_t x, size_t y, unsigned char* r, unsigned char* g, unsigned char* b, unsigned char* a)
    {
        unsigned bytePerPixel = 4;
        unsigned char* pixelOffset = image + (x + imageWidth * y) * bytePerPixel;
        *r = pixelOffset[0];
        *g = pixelOffset[1];
        *b = pixelOffset[2];
        *a = pixelOffset[3]; //8 >= 4 ? pixelOffset[3] : 0xff;
    }

	void ImageMisc::GetPixelNeighbourhood(stbi_uc* image, size_t imageWidth, int poi, int matrix_size, std::shared_ptr<std::vector<Pixel>> pixel_neighbourhood, int &centre_point)
	{
		unsigned bytePerPixel = 4;
		unsigned char* pixelOffset = 0;

		size_t x;
		size_t y;

		int temp_poi;

		centre_point = matrix_size * matrix_size / 2;

		if (matrix_size == 3)
		{
			for (auto i = 0; i < matrix_size * matrix_size; i++)
			{
				if (i < matrix_size)
				{
					temp_poi = poi - imageWidth - matrix_size / 2 + i;
					x = temp_poi % imageWidth;
					y = temp_poi / imageWidth;
					pixelOffset = image + (x + imageWidth * y) * bytePerPixel;
				}
				else if (i < matrix_size * 2)
				{
					temp_poi = poi - matrix_size / 2 + i - matrix_size;
					x = temp_poi % imageWidth;
					y = temp_poi / imageWidth;
					pixelOffset = image + (x + imageWidth * y) * bytePerPixel;
				}
				else if (i < matrix_size * matrix_size)
				{
					temp_poi = poi + imageWidth - matrix_size / 2 + i - matrix_size * 2;
					x = temp_poi % imageWidth;
					y = temp_poi / imageWidth;
					pixelOffset = image + (x + imageWidth * y) * bytePerPixel;
				}

				pixel_neighbourhood->push_back(Pixel(((float)pixelOffset[0] / 255.0f), ((float)pixelOffset[1] / 255.0f), ((float)pixelOffset[2] / 255.0f), ((float)pixelOffset[3] / 255.0f)));
			}
		}
		else if (matrix_size == 5)
		{
			for (auto i = 0; i < matrix_size * matrix_size; i++)
			{
				if (i < matrix_size)
				{
					temp_poi = poi - imageWidth - imageWidth - matrix_size / 2 + i;
					x = temp_poi % imageWidth;
					y = temp_poi / imageWidth;
					pixelOffset = image + (x + imageWidth * y) * bytePerPixel;
				}
				else if (i < matrix_size * 2)
				{
					temp_poi = poi - imageWidth - matrix_size / 2 + i - matrix_size;
					x = temp_poi % imageWidth;
					y = temp_poi / imageWidth;
					pixelOffset = image + (x + imageWidth * y) * bytePerPixel;
				}
				else if (i < matrix_size * 3)
				{
					temp_poi = poi - matrix_size / 2 + i - matrix_size * 2;
					x = temp_poi % imageWidth;
					y = temp_poi / imageWidth;
					pixelOffset = image + (x + imageWidth * y) * bytePerPixel;
				}
				else if (i < matrix_size * 4)
				{
					temp_poi = poi + imageWidth - matrix_size / 2 + i - matrix_size * 3;
					x = temp_poi % imageWidth;
					y = temp_poi / imageWidth;
					pixelOffset = image + (x + imageWidth * y) * bytePerPixel;
				}
				else if (i < matrix_size * matrix_size)
				{
					temp_poi = poi + imageWidth + imageWidth - matrix_size / 2 + i - matrix_size * 4;
					x = temp_poi % imageWidth;
					y = temp_poi / imageWidth;
					pixelOffset = image + (x + imageWidth * y) * bytePerPixel;
				}

				pixel_neighbourhood->push_back(Pixel(((float)pixelOffset[0] / 255.0f), ((float)pixelOffset[1] / 255.0f), ((float)pixelOffset[2] / 255.0f), ((float)pixelOffset[3] / 255.0f)));
			}
		}
	}

	void ImageMisc::SavePixel(stbi_uc* data, size_t imageWidth, size_t x, size_t y, unsigned char* r = NULL, unsigned char* g = NULL, unsigned char* b = NULL, unsigned char* a = NULL)
    {
        unsigned bytePerPixel = 4;
    	unsigned char* pixelOffset = data + (x + imageWidth * y) * bytePerPixel;
    	if(*r != NULL)
			pixelOffset[0] = *r;
    	if(*g != NULL)
			pixelOffset[1] = *g;
        if(*b != NULL)
    		pixelOffset[2] = *b;
        if(*a != NULL)
    		pixelOffset[3] = *a;
    }

	//SAVE PIXEL?

    void ImageMisc::WriteImage(char const* filename, int x, int y, int comp, const void* data)
    {
        stbi_write_bmp(filename, x, y, comp, data);
    }


