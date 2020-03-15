// RayTracerApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include "pch.h"

#include "Sphere.h"
#include "Surface.h"


void ShowNum(int num);

int main()
{
	// #1
	std::cout << "#1: Hello World" << std::endl;

	// #2
	ShowNum(2);

	const Sphere S(Vector(0, 0, 0), 10);
	std::cout << S << std::endl;

	// #3
	ShowNum(3);

	const Ray R1(Vector(0, 0, -20), Vector(0, 0, -1));
	std::cout << R1 << std::endl;

	// #4
	ShowNum(4);

	const Ray R2(R1.Origin(), Vector(0, 1, 0));
	std::cout << R2 << std::endl;

	// #5
	ShowNum(5);

	float length = 0;
	Vector point = Vector::Zero();
	float result = S.Intersection(R1, point, length);

	if (result != 0)
	{
		std::cout << point << std::endl;
	}
	else
	{
		std::cout << "MISS" << std::endl;
	}

	///////////////////////

	length = 0;
	point = Vector::Zero();
	result = S.Intersection(R2, point, length);

	if (result != 0)
	{
		std::cout << point << std::endl;
	}
	else
	{
		std::cout << "MISS" << std::endl;
	}

	// #6
	ShowNum(6);

	Ray R3(Vector(0, 0, -24), Vector(0, 0, 1));

	float length2 = 0;
	Vector point2 = Vector::Zero();
	float result2 = S.Intersection(R3, point2, length2);

	if (result2 != 0)
	{
		std::cout << point2 << std::endl;
	}
	else
	{
		std::cout << "MISS" << std::endl;
	}


	// #7
	ShowNum(7);

	Surface P(Vector(0, 1, 1), Vector(0, 0, 0));
	Vector y(0, 1, 0);
	Vector z(0, 0, 1);

	std::cout << std::to_string(P.GetAngleBetweenNormalAndVector(y)) << std::endl;
	std::cout << std::to_string(P.GetAngleBetweenNormalAndVector(z)) << std::endl;
	

	// #8
	ShowNum(8);

	float dis = 0;
	Vector point3;
	bool result3 = P.Intersection(R2, dis, point3);

	std::cout << point3 << std::endl;
}

void ShowNum(int num)
{
	std::cout << std::endl << std::endl << std::endl << std::endl << "# " << std::to_string(num) << ": " << std::endl;
}