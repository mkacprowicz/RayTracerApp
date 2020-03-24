// RayTracerApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include "pch.h"

#include "Sphere.h"
#include "Surface.h"
#include "PerspectiveCamera.h"
#include "OrtoCamera.h"

#include "LightIntensity.h"
#include "Image.hpp"


float RandomFloat();

int main()
{
	std::cout << "Hello World" << std::endl;

	Image img(800, 800, 100);

	PerspectiveCamera pCam;

	Sphere s(Vector(0, 0, -1.0f), 0.4f);
	Sphere s2(Vector(0.6f, 0, -1.5f), 0.4f);

	for (auto j = img.Height() - 1; j >= 0; j--)
	{
		for (auto i = 0; i < img.Width(); i++)
		{
			LightIntensity color;

			auto u = (i + RandomFloat()) / img.Width();
			auto v = (j + RandomFloat()) / img.Height();
			Ray ray = pCam.GetRay(u, v);

			bool intersection = s.Hit(ray, 0.0f, FLT_MAX);
			bool intersection2 = s2.Hit(ray, 0.0f, FLT_MAX);


			if (intersection)
			{
				color.R(0);
				color.G(0);
				color.B(255);
				color.A(255);
			}
			else if (intersection2)
			{
				color.R(255);
				color.G(0);
				color.B(0);
				color.A(255);
			}
			else
			{
				color.R(255);
				color.G(255);
				color.B(255);
				color.A(255);
			}

			img.SavePixel(color);
		}
	}

	img.WriteImage("Results//resultPer.bmp", img.Width(), img.Height(), 4);


	OrtoCamera oCam;

	img.OutputImageData().clear();

	for (auto j = img.Height() - 1; j >= 0; j--)
	{
		for (auto i = 0; i < img.Width(); i++)
		{
			LightIntensity color;

			auto u = (i + RandomFloat()) / img.Width();
			auto v = (j + RandomFloat()) / img.Height();
			Ray ray = oCam.GetRay(u, v);

			bool intersection = s.Hit(ray, 0.0f, FLT_MAX);
			bool intersection2 = s2.Hit(ray, 0.0f, FLT_MAX);


			if (intersection)
			{
				color.R(0);
				color.G(0);
				color.B(255);
				color.A(255);
			}
			else if (intersection2)
			{
				color.R(255);
				color.G(0);
				color.B(0);
				color.A(255);
			}
			else
			{
				color.R(255);
				color.G(255);
				color.B(255);
				color.A(255);
			}

			img.SavePixel(color);
		}
	}

	img.WriteImage("Results//resultOrto.bmp", img.Width(), img.Height(), 4);

	std::cout << "Done" << std::endl;
}

float RandomFloat()
{
	return rand() / (RAND_MAX + 1.0f);
}