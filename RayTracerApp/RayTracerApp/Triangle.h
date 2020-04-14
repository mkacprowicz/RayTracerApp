#pragma once

#include "pch.h"
#include "GeometricShape.h"

class Triangle : public GeometricShape
{
public:
	Triangle();
	Triangle(Vector a, Vector b, Vector c);

	bool Intersection(Ray ray, float& t0, float& t1);

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
};

