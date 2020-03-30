// RayTracerApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include "pch.h"

#include "Sphere.h"
#include "Surface.h"
#include "PersCamera.h"

#include "LightIntensity.h"
#include "Image.hpp"

#include "Triangle.h"
#include "Mesh.h"

float RandomFloat();

int main()
{
	std::cout << "Hello World" << std::endl;

	Image img(800, 800, 100);

	PersCamera pCam(Vector(0, 0, -4.0f), Vector(0, 0, 0), Vector(0, -1.0f ,0), 1);

	Sphere s(Vector(-4.f, 0, 0), 2.0f);
	Sphere s2(Vector(4.f, 0, 0), 2.0f);
	Sphere s3(Vector(0.f, 0, 3.0f), 2.0f);

	Mesh m;

	m.ReadMeshFromFile(std::string("gourd.obj"));

	for (auto x = 0; x < img.Width(); x++)
	{
		for (auto y = 0; y < img.Height(); y++)
		{
			LightIntensity color;

			float u = ((y + RandomFloat()) / (float)img.Width()) * 2.0f - 1.0f;
			float v = ((x + RandomFloat()) / (float)img.Height()) * 2.0f - 1.0f;
			Ray ray = pCam.GetRay(u, v);

			bool intersection = s.Hit(ray, 0.0f, FLT_MAX);
			bool intersection2 = s2.Hit(ray, 0.0f, FLT_MAX);
			bool intersection3 = s3.Hit(ray, 0.0f, FLT_MAX);


			
			if (m.CheckIntersection(ray))
			{
				color.R(0);
				color.G(0);
				color.B(255);
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

	img.WriteImage("Results//result.bmp", img.Width(), img.Height(), 4);

	std::cout << "Done" << std::endl;
}

float RandomFloat()
{
	return rand() / (RAND_MAX + 1.0f);
}