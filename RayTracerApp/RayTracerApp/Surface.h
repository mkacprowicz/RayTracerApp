#pragma once
#include "pch.h"
#include "GeometricShape.h"

class Surface : public GeometricShape
{
public:
	Surface();
	Surface(Vector poi, Vector nor);
	Surface(Vector poi, Vector nor, std::shared_ptr<Material> mat);

	bool HitTest(Ray ray, float& distance, Vector& normal);

	float GetAngleBetweenNormalAndVector(Vector vec);
	bool Intersection(Ray ray, float& dist, Vector& point);

	Vector Normal() const { return Normal_; }
	void Normal(Vector d) { Normal_ = d; }
	Vector Point() const { return Point_; }
	void Point(Vector p) { Point_ = p; }	

private:
	Vector Normal_;
	Vector Point_;
};

