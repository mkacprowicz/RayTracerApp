#pragma once

#include "pch.h"
#include "Color.h"
#include "World.h"
#include "Camera.h"
#include "OrtogonalCamera.h"
#include "Sampler.h"
#include "Material.h"

//! ImageRT class which is a representation of a image
/**
* The <code>ImageRT</code> class represents an image to render. Contains image height and width, vector with image pixels and number of samples to sampling.
*/

class ImageRT : public std::enable_shared_from_this<ImageRT>
{
public:
	ImageRT(int h, int w);
	ImageRT(int h, int w, int maxDepth);

	void RayTrace(std::shared_ptr<World> world, std::shared_ptr<Camera> camera);
	void RayTrace(std::shared_ptr<World> world, std::shared_ptr<Camera> camera, std::shared_ptr<Sampler> sampler);
	
	Color ShadeRay(std::shared_ptr<World> world, Ray ray, int currentDepth, Vector2 uv);
	Color ShadeRay(std::shared_ptr<World> world, Ray ray, int currentDepth);

	void WriteImage(char const* filename, int x, int y, int comp);

	void SavePixel(Color li);

	int Height() const { return Height_; }
	void Height(int height) { Height_ = height; }
	int Width() const { return Width_; }
	void Width(int width) { Width_ = width; }
	int MaxDepth() const { return MaxDepth_; }
	void MaxDepth(int m) { MaxDepth_ = m; }

private:
	int Height_;
	int Width_;
	int MaxDepth_;

	std::vector<unsigned char> OutputImageData_;
};

