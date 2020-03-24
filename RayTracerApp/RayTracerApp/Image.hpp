#pragma once

#include "pch.h"

class Image
{
public:
	Image(int h, int w, int s);

	void WriteImage(char const* filename, int x, int y, int comp, const void* data);

	int Height() const { return Height_; }
	void Height(int height) { Height_ = height; }
	int Width() const { return Width_; }
	void Width(int width) { Width_ = width; }
	int SamplesPerPixel() const { return SamplesPerPixel_; }
	void SamplesPerPixel(int samplesPerPixel) { SamplesPerPixel_ = samplesPerPixel; }

private:
	int Height_;
	int Width_;
	int SamplesPerPixel_;
};

