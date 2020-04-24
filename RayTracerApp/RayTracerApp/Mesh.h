#pragma once
#include "pch.h"
#include "Triangle.h"

#include "Ray.h"

struct Face
{
	int A;
	int B;
	int C;

	Face(int a, int b, int c) : A(a), B(b), C(c) {};
};

class Mesh
{
public:
	Mesh();

	void PutNextTriangle(Triangle t);
	void ReadMeshFromFile(std::string filename);

	void AddVertex(float x, float y, float z);
	void AddFace(int a, int b, int c);
	void ComputeNormals();

	int AbsoludeNdx(int n);

	Vector GetNormal(Face face);

	std::shared_ptr<std::vector<Triangle>> Shape() { return this->Shape_; };
	std::shared_ptr<std::vector<Vector>> Verctices() { return this->Verticles_; };
	std::shared_ptr<std::vector<Vector>> Normals() { return this->Normals_; };
	std::shared_ptr<std::vector<Face>> Faces() { return this->Faces_; };


private:
	std::shared_ptr<std::vector<Triangle>> Shape_;

	std::shared_ptr<std::vector<Vector>> Verticles_;
	std::shared_ptr<std::vector<Vector>> Normals_;
	std::shared_ptr<std::vector<Face>> Faces_;
};

