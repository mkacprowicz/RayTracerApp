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

#include "Triangle.h"
#include "Mesh.h"

float RandomFloat();

int main()
{
	std::cout << "Hello World" << std::endl;

	Image img(800, 800, 100);

	PerspectiveCamera pCam;

	Sphere s(Vector(0, 0, -1.0f), 0.4f);
	Sphere s2(Vector(0.6f, 0, -1.5f), 0.4f);

	Triangle t1(Vector(0.6f, 0, -1.5f), Vector(0.5f, 0.5f, -1.1f), Vector(0.9f, 0.3f, -1.5f));

	Triangle t2(Vector(4.528552, 0.063698, -0.076053), Vector(4.401397, 0.491405, -0.060543), Vector(4.065627, 0.801094, -0.045114));


	for (auto j = img.Height() - 1; j >= 0; j--)
	{
		for (auto i = 0; i < img.Width(); i++)
		{
			LightIntensity color;

			auto u = (i + RandomFloat()) / img.Width();
			auto v = (j + RandomFloat()) / img.Height();
			Ray ray = pCam.GetRay(u, v);

			//bool intersection = s.Hit(ray, 0.0f, FLT_MAX);
			//bool intersection2 = s2.Hit(ray, 0.0f, FLT_MAX);

			float ad = 0;
	
			bool intersection3 = t2.Intersection(ray, ad, ad);


			/*if (intersection)
			{
				color.R(0);
				color.G(0);
				color.B(255);
				color.A(255);
			}
			else*/ if (intersection3)
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


			/*if (intersection3)
			{
				color.R(0);
				color.G(255);
				color.B(0);
				color.A(255);
			}*/


			img.SavePixel(color);
		}
	}

	img.WriteImage("Results//result.bmp", img.Width(), img.Height(), 4);


	std::cout << "Done" << std::endl;
}

float RandomFloat()
{
	return rand() / (RAND_MAX + 1.0f);
}