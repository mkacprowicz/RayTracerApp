#include "ImageRT.h"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "vendor/stb_image/stb_image.h"
#include "vendor/stb_image/stb_image_write.h"

/**
* Basic constructor. Creates an image to prepare file to render
* @param h - height of image
* @param w - widht of image
* @returns ImageRT object
*/
ImageRT::ImageRT(int h, int w)
{
	this->Height_ = h;
	this->Width_ = w;
	this->OutputImageData_.clear();
	this->MaxDepth_ = 1;
}

ImageRT::ImageRT(int h, int w, int maxDepth)
{
	this->Height_ = h;
	this->Width_ = w;
	this->OutputImageData_.clear();
	this->MaxDepth_ = maxDepth;
}

/**
* Function that render image, and save to file
* @param world - world, contains all objects in scene
* @param camera - camera, from which one, image will be rendered
*/
void ImageRT::RayTrace(std::shared_ptr<World> world, std::shared_ptr<Camera> camera)
{
	for (auto y = 0; y < this->Height_; y++)
	{
		for (auto x = 0; x < this->Width_; x++)
		{
			Vector2 pictureCoordinates(((x + 0.5f) / this->Width_) * 2 - 1, ((y + 0.5f) / this->Height_) * 2 - 1);

			Ray ray = camera->GetRay(pictureCoordinates);

			Color resultColor = ShadeRay(world, ray, 0, pictureCoordinates);

			SavePixel(resultColor);
		}
	}
}
/**
* Function that render image, and save to file
* @param world - world, contains all objects in scene
* @param camera - camera, from which one, image will be rendered
* @param sampler - sampler, that contains samples to antyaliasing
*/
void ImageRT::RayTrace(std::shared_ptr<World> world, std::shared_ptr<Camera> camera, std::shared_ptr<Sampler> sampler)
{
	for (auto y = 0; y < this->Height_; y++)
	{
		for (auto x = 0; x < this->Width_; x++)
		{
			Color totalColor(0, 0, 0);

			for (auto i = 0; i < sampler->SampleCount(); i++)
			{
				Vector2 sample = sampler->Single();

				Vector2 pictureCoordinates(((x + sample.X()) / this->Width_) * 2 - 1, ((y + sample.Y()) / this->Height_) * 2 - 1);

				Ray ray = camera->GetRay(pictureCoordinates);

				Color temp = ShadeRay(world, ray, 0, pictureCoordinates) / (float)sampler->SampleCount();
				totalColor = totalColor + temp;
			}

			SavePixel(totalColor);
		}

		float prog = (100.f * y) / Height();
		std::cout << "Progres: " << prog << "%\n";
	}
}

/**
* Function that counting color per pixel
* @param world - world, contains all objects in scene
* @param ray - ray, that will be counting per pixel
* @param currenthDepth - maximum numbers of reflections
* @param uv - picture UV coordinates
* @return Color object
*/
Color ImageRT::ShadeRay(std::shared_ptr<World> world, Ray ray, int currentDepth, Vector2 uv)
{
	if (currentDepth > this->MaxDepth_)
	{
		return Color(0, 0, 0);
	}

	std::shared_ptr<HitInfo> info = world->TraceRay(ray);


	info->Depth(currentDepth + 1);

	if (info->HitObject() == nullptr)
	{
		return world->BackgroundColor();
	}

	auto material = info->HitObject()->ShapeMaterial();

	material->UV = uv;

	return material->Shade(shared_from_this(), info);
}

/**
* Function that writing image data to bmp file
* @param filename - filename of bmp file
* @param x - widht of file to save
* @param y - height of file to save
* @param comp - numbers of color channels
*/
void ImageRT::WriteImage(char const* filename, int x, int y, int comp)
{
	stbi_write_bmp(filename, x, y, comp, this->OutputImageData_.data());
}

/**
* Function that writing image data to bmp file
* @param li - Color object to save
*/
void ImageRT::SavePixel(Color c)
{
	this->OutputImageData_.push_back(c.R());
	this->OutputImageData_.push_back(c.G());
	this->OutputImageData_.push_back(c.B());
	this->OutputImageData_.push_back(c.A());
}
