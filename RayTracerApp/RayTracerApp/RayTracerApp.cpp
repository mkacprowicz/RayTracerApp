// RayTracerApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include "pch.h"

#include "ImageRT.h"
#include "World.h"
#include "Material.h"
#include "PerfectDiffuse.h"
#include "Phong.h"
#include "Reflective.h"
#include "Transparent.h"

#include "Sampler.h"
#include "SampleDistributor.h"
#include "SampleGenerator.h"
#include "Regular.h"
#include "SquareDistributor.h"

#include "PerspectiveCamera.h"
#include "OrtogonalCamera.h"

#include "Sphere.h"
#include "Surface.h"
#include "Triangle.h"
#include "Mesh.h"

#include "Texture.h"

#include "vendor/stb_image/stb_image.h"
#include "vendor/stb_image/stb_image_write.h"

int main()
{
	std::cout << "Hello World" << std::endl;

	std::shared_ptr<ImageRT> img = std::make_shared<ImageRT>(800, 800, 5);

	auto world = std::make_shared<World>(Color(94, 188, 255));

	auto cameraP = std::make_shared<PerspectiveCamera>(Vector(0, 2, -8), Vector(0, 0, 0), Vector(0, -1, 0), 1);


	auto floorMat = std::make_shared<PerfectDiffuse>(Color(180, 180, 180));
	auto floorMat2 = std::make_shared<PerfectDiffuse>(Color(0, 0, 0));

	auto wallMat = std::make_shared<PerfectDiffuse>(Color(255, 0, 0));
	auto wallMat2 = std::make_shared<PerfectDiffuse>(Color(0, 0, 255));

	auto leftBallMat = std::make_shared<Reflective>(Color(255, 255, 255), 0.2f, 1, 1300, 0.95f);
	auto rightBallMat = std::make_shared<Transparent>(Color(0, 0, 255), 0.1f, 0, 0, 0.3, 1.05f, 0.9f);

	
	world->AddObject(std::make_shared<Sphere>(Vector(1.f, 0, 2.5f), 2, leftBallMat));
	world->AddObject(std::make_shared<Sphere>(Vector(-2.f, 0, 2.5f), 2, leftBallMat));
	world->AddObject(std::make_shared<Sphere>(Vector(1.f, 0, 0.f), 2, rightBallMat));
	world->AddObject(std::make_shared<Surface>(Vector(0, -2, 0), Vector(0, 1, 0), floorMat));
	world->AddObject(std::make_shared<Surface>(Vector(0, 10, 0), Vector(0, -1, 0), floorMat2));
	world->AddObject(std::make_shared<Surface>(Vector(0, 0, 10), Vector(0, 0, -1), floorMat));
	world->AddObject(std::make_shared<Surface>(Vector(0, 0, -12), Vector(0, 0, 1), floorMat2));
	world->AddObject(std::make_shared<Surface>(Vector(-8, 0, 0), Vector(1, 0, 0), wallMat));
	world->AddObject(std::make_shared<Surface>(Vector(8, 0, 0), Vector(-1, 0, 0), wallMat2));


	const int SampleCt = 9;
	auto antiAlias = std::make_shared<Sampler>(std::make_shared<Regular>(), std::make_shared<SquareDistributor>(), SampleCt, 4);

	world->AddLight(std::make_shared<PointLight>(Vector(0, 5, -5), Color(255, 255, 255)));

	img->RayTrace(world, cameraP, antiAlias);
	img->WriteImage("Results//result.bmp", img->Width(), img->Height(), 4);

	std::cout << "Done" << std::endl;
	system("Results\\result.bmp");
}