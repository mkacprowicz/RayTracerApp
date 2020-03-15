#pragma once
#include "pch.h"
#include "Ray.h"

class Sphere
{
public:
	Sphere();
	Sphere(float r);
	Sphere(Vector v);
	Sphere(Vector v, float r);

	int Intersection(Ray ray, float & dist, Vector &p) const;

	Vector Center() const { return Center_; }
	void Center(Vector o) { Center_ = o; }
	float Radius() const { return Radius_; }
	void Radius(float r) { Radius_ = r; }

	friend std::ostream& operator <<(std::ostream& os, const Sphere& sph);
private:
	Vector Center_;
	float Radius_;
};

