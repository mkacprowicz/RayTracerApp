#pragma once
#include "pch.h"
#include "Triangle.h"

#include "Ray.h"

class Mesh
{
public:
	Mesh();

	void PutNextTriangle(Triangle t);
	void ReadMeshFromFile(std::string filename);

	bool CheckIntersection(Ray ray);

private:
	std::shared_ptr<std::vector<Triangle>> Shape_;
};

