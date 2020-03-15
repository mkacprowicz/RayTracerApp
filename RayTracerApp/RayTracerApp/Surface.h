#pragma once
#include "pch.h"
#include "Ray.h"

class Surface
{
public:
	Surface();
	Surface(Vector nor, Vector poi);

	Vector Normal() const { return Normal_; }
	void Normal(Vector d) { Normal_ = d; }
	Vector Point() const { return Point_; }
	void Point(Vector d) { Point_ = d; }

	float GetAngleBetweenNormalAndVector(Vector vec);
	bool Intersection(Ray ray, float & dist, Vector &point);


private:
	Vector Normal_;
	Vector Point_;
};

