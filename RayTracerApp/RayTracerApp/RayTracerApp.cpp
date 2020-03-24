// RayTracerApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include "pch.h"

#include "Sphere.h"
#include "Surface.h"
#include "Camera.h"

#include "ImageLoader.hpp"

void ShowNum(int num);
float RandomFloat();

int main()
{
	std::cout << "Hello World" << std::endl;

	std::vector<unsigned char> output_image_data;

	int image_width = 800;
	int image_height = 800;
	int samples_per_pixel = 100;

	Camera cam;

	Sphere s(Vector(0, 0, -1.0f), 0.5f);
	Sphere s2(Vector(0.9f, 0, -2.0f), 0.7f);

	Vector left_corner(-2.0f, -1.0f, -1.0f);
	Vector horizontal(4.0f, 0.0f, 0.0f);
	Vector vertical(0.0f, 2.0f, 0.0f);
	Vector origin(0.0f, 0.0f, 0.0f);

	for (auto j = image_height - 1; j >= 0; j--)
	{
		for (auto i = 0; i < image_width; i++)
		{
			int color;

			for (auto k = 0; k < samples_per_pixel; k++)
			{
				auto u = (i + RandomFloat()) / image_width;
				auto v = (j + RandomFloat()) / image_height;
				Ray ray = cam.GetRay(u, v);

				
				bool intersection = s.Hit(ray, 0.0f, FLT_MAX);
				bool intersection2 = s2.Hit(ray, 0.0f, FLT_MAX);

				if (intersection)
				{
					color = 255;
				}
				else if (intersection2)
				{
					color = 100;
				}
				else
				{
					color = 0;
				}
			}

			output_image_data.push_back(color);
			output_image_data.push_back(0);
			output_image_data.push_back(0);
			output_image_data.push_back(255);
		}
	}



	ImageMisc::WriteImage("resultFile.bmp", image_width, image_height, 4, output_image_data.data());

	std::cout << "Done" << std::endl;
}

void ShowNum(int num)
{
	std::cout << std::endl << std::endl << std::endl << std::endl << "# " << std::to_string(num) << ": " << std::endl;
}

float RandomFloat()
{
	return rand() / (RAND_MAX + 1.0f);
}