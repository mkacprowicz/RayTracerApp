#include "Mesh.h"

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


}
