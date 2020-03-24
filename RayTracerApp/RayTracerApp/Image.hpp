#pragma once

#include "pch.h"
#include "LightIntensity.h"

//! Image class which is a representation of a image
/**
* The <code>Image</code> class represents an image to render. Contains image height and width, vector with image pixels and number of samples to sampling.
*/

class Image
{
public:
	Image(int h, int w, int s);

	void WriteImage(char const* filename, int x, int y, int comp);

	int Height() const { return Height_; }
	void Height(int height) { Height_ = height; }
	int Width() const { return Width_; }
	void Width(int width) { Width_ = width; }
	int SamplesPerPixel() const { return SamplesPerPixel_; }
	void SamplesPerPixel(int samplesPerPixel) { SamplesPerPixel_ = samplesPerPixel; }

	std::vector<unsigned char> OutputImageData() const { return *OutputImageData_;  }
	void OutputImageData(std::vector<unsigned char> outputImageData) { *OutputImageData_ = outputImageData; }

	void SavePixel(LightIntensity li);

private:
	int Height_;
	int Width_;
	int SamplesPerPixel_;
	std::shared_ptr<std::vector<unsigned char>> OutputImageData_;
};

