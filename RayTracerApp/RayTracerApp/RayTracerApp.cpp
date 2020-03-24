// RayTracerApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include "pch.h"

#include "Sphere.h"
#include "Surface.h"
#include "PerspectiveCamera.h"
#include "OrtoCamera.h"

#include "ImageLoader.hpp"

float RandomFloat();

int main()
{
	std::cout << "Hello World" << std::endl;

	std::vector<unsigned char> output_image_data;

	int image_width = 800;
	int image_height = 800;
	int samples_per_pixel = 100;

	PerspectiveCamera pCam;
	
	Sphere s(Vector(0, 0, -1.0f), 0.4f);
	Sphere s2(Vector(0.6f, 0, -1.5f), 0.4f);

	for (auto j = image_height - 1; j >= 0; j--)
	{
		for (auto i = 0; i < image_width; i++)
		{
			Vector color;

			//for (auto k = 0; k < samples_per_pixel; k++)
			{
				auto u = (i + RandomFloat()) / image_width;
				auto v = (j + RandomFloat()) / image_height;
				Ray ray = pCam.GetRay(u, v);
							
				bool intersection = s.Hit(ray, 0.0f, FLT_MAX);
				bool intersection2 = s2.Hit(ray, 0.0f, FLT_MAX);


				if (intersection)
				{
					color.X(0);
					color.Y(0);
					color.Z(255);
				}
				else if (intersection2)
				{
					color.X(255);
					color.Y(0);
					color.Z(0);
				}
				else
				{
					color.X(255);
					color.Y(255);
					color.Z(255);
				}
			}

			output_image_data.push_back(color.X());
			output_image_data.push_back(color.Y());
			output_image_data.push_back(color.Z());
			output_image_data.push_back(255);
		}
	}

	ImageMisc::WriteImage("resultPer.bmp", image_width, image_height, 4, output_image_data.data());


	OrtoCamera oCam;

	output_image_data.clear();

	for (auto j = image_height - 1; j >= 0; j--)
	{
		for (auto i = 0; i < image_width; i++)
		{
			Vector color;

			//for (auto k = 0; k < samples_per_pixel; k++)
			{
				auto u = (i + RandomFloat()) / image_width;
				auto v = (j + RandomFloat()) / image_height;
				Ray ray = oCam.GetRay(u, v);

				bool intersection = s.Hit(ray, 0.0f, FLT_MAX);
				bool intersection2 = s2.Hit(ray, 0.0f, FLT_MAX);


				if (intersection)
				{
					color.X(0);
					color.Y(0);
					color.Z(255);
				}
				else if (intersection2)
				{
					color.X(255);
					color.Y(0);
					color.Z(0);
				}
				else
				{
					color.X(255);
					color.Y(255);
					color.Z(255);
				}
			}

			output_image_data.push_back(color.X());
			output_image_data.push_back(color.Y());
			output_image_data.push_back(color.Z());
			output_image_data.push_back(255);
		}
	}

	ImageMisc::WriteImage("resultOrto.bmp", image_width, image_height, 4, output_image_data.data());

	std::cout << "Done" << std::endl;
}

float RandomFloat()
{
	return rand() / (RAND_MAX + 1.0f);
}