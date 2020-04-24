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

	auto cameraO = std::make_shared<OrtogonalCamera>(Vector(0, 0, -5), 0, Vector2(5, 5));
	auto cameraP = std::make_shared<PerspectiveCamera>(Vector(0, 1, -8), Vector(0, 0, 0), Vector(0, -1, 0), 1);


	std::shared_ptr<Texture> textureTiles = std::make_shared<Texture>("tiles.bmp");
	std::shared_ptr<Texture> textureTex1 = std::make_shared<Texture>("Tex1.bmp");

	auto redMat = std::make_shared<Reflective>(Color(255, 0, 0), 0.8f, 1, 300, 0.2f);
	auto texMat = std::make_shared<PerfectDiffuse>(Color(255, 255, 255), textureTiles);
	auto texTexMat = std::make_shared<PerfectDiffuse>(Color(255, 255, 255), textureTex1);
	auto greenMat = std::make_shared<Reflective>(Color(0, 255, 0), 0.4f, 1, 300, 0.6f);
	auto blueMat = std::make_shared<Reflective>(Color(0, 0, 255), 0.2f, 1, 300, 0.8f);
	auto grayMat = std::make_shared<Reflective>(Color(180, 180, 180), 0.4f, 1, 300, 0.6f);


	world->AddObject(std::make_shared<Sphere>(Vector(-8.0f, 0, 4), 2, redMat));
	world->AddObject(std::make_shared<Sphere>(Vector(3.6f, 0, -2.0f), 2, texTexMat));
	//world->AddObject(std::make_shared<Sphere>(Vector(0.f, 0, 3.f), 2, blueMat));
	world->AddObject(std::make_shared<Surface>(Vector(0, -2, 0), Vector(0, 1, 0), grayMat));

	Mesh object;
	object.ReadMeshFromFile(std::string("Box.obj"));
	object.ComputeNormals();

	for (int i = 0; i < object.Shape()->size(); i++)
	{
		auto tri = object.Shape()->data()[i];	
		world->AddObject(std::make_shared<Triangle>(tri.A(), tri.B(), tri.C(), texMat));
	}

	world->AddLight(std::make_shared<PointLight>(Vector(0, 5, -5), Color(255, 255, 255)));

	const int SampleCt = 9;
	auto antiAlias = std::make_shared<Sampler>(std::make_shared<Regular>(), std::make_shared<SquareDistributor>(), SampleCt, 4);

	img->RayTrace(world, cameraP, antiAlias);
	img->WriteImage("Results//result.bmp", img->Width(), img->Height(), 4);

	std::cout << "Done" << std::endl;
	system("Results\\result.bmp");
}