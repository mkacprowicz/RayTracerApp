#pragma once

#include "pch.h"
#include "Triangle.h"

class Mesh
{
public:
	Mesh();

	void PutNextTriangle(Triangle t);
	void ReadMeshFromFile(std::string filename);

private:
	std::shared_ptr<std::vector<Triangle>> Shape_;
};

