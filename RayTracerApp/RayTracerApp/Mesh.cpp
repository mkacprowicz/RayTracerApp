#include "Mesh.h"

#include "OBJ_Loader.h"

Mesh::Mesh()
{
	this->Shape_ = std::make_shared <std::vector<Triangle>>();
	this->Shape_->clear();
}

void Mesh::PutNextTriangle(Triangle t)
{
	this->Shape_->push_back(t);
}

std::vector<std::string> split(const std::string& str, const char& delimit)
{
	std::vector<std::string> result;
	std::string data;
	std::stringstream ss(str);
	while (getline(ss, data, delimit))
	{
		result.push_back(data);
	}
	return result;
}

void Mesh::ReadMeshFromFile(std::string filename)
{
	objl::Loader loader;

	loader.LoadFile(filename);

	for (auto i = 0; i < loader.LoadedVertices.size(); i = i + 3)
	{
		Vector a(loader.LoadedVertices.at(i).Position.X, loader.LoadedVertices.at(i).Position.Y, loader.LoadedVertices.at(i).Position.Z);
		Vector b(loader.LoadedVertices.at(i + 1).Position.X, loader.LoadedVertices.at(i + 1).Position.Y, loader.LoadedVertices.at(i + 1).Position.Z);
		Vector c(loader.LoadedVertices.at(i + 2).Position.X, loader.LoadedVertices.at(i + 2).Position.Y, loader.LoadedVertices.at(i + 2).Position.Z);

		this->Shape_->push_back(Triangle(a, b, c));
	}
}

bool Mesh::CheckIntersection(Ray ray)
{
	bool check = false;
	float ad = 0;

	for (auto vector : *this->Shape_)
	{
		if (vector.Intersection(ray, ad, ad))
		{
			check = true;
		}
	}

	return check;
}
