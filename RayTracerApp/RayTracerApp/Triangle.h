#pragma once

#include "pch.h"
#include "GeometricShape.h"

//! Traingle is a class which is a representation of a triangle GeometricShape
class Triangle : public GeometricShape
{
public:
	Triangle();
	Triangle(Vector a, Vector b, Vector c);
	Triangle(Vector vertexa, Vector vertexb, Vector vertexc, std::shared_ptr<Material> mat);
	Triangle(Vector vertexa, Vector vertexb, Vector vertexc, Vector normala, Vector normalb, Vector normalc, std::shared_ptr<Material> mat);

	bool HitTest(Ray ray, float& distance, Vector& normal);

	Vector A() const { return A_; }
	void A(Vector a) { A_ = a; }
	Vector B() const { return B_; }
	void B(Vector b) { B_ = b; }
	Vector C() const { return C_; }
	void C(Vector c) { C_ = c; }

private:
	Vector A_;
	Vector B_;
	Vector C_;

	Vector VertexA;
	Vector EdgeAB;
	Vector EdgeAC;
	Vector NormalA;
	Vector NormalAB;
	Vector NormalAC;
};

