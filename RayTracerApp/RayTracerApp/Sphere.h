#pragma once
#include "pch.h"
#include "Ray.h"

//! Sphere class which is a representation of a sphere solid
/**
* The <code>Sphere</code> class is a representation of a Set of points that are equaly apart (sphere radius) in a 3D space.
* In order to define a sphere, we need to determine it's center, with a Point or Vector, and it's radius - real number.
* Sphere that has a center equal to \f$ c = (c_x, c_y, c_z) \f$ and radius equal to \f$ R \f$ can be determied with a formula:
* \f[
* (x-c_x)^2 + (y-c_y)^2 + (z-c_z)^2 - R^2 = 0
* \f]
* which is equivalent to a vector formula:
* \f[
* (p-c) \cdot (p-c) - R^2 = 0
* \f]
* Every point that satisfies that equation belongs to the sphere. 
*/
class Sphere
{
public:
	Sphere();
	Sphere(float r);
	Sphere(Vector v);
	Sphere(Vector v, float r);

	float Intersection(Ray ray, Vector &p, float& t) const;
	bool Intersection(Ray ray) const;
	bool IntersectionB(Ray ray) const;

	Vector Center() const { return Center_; }
	void Center(Vector o) { Center_ = o; }
	float Radius() const { return Radius_; }
	void Radius(float r) { Radius_ = r; }

	friend std::ostream& operator <<(std::ostream& os, const Sphere& sph);
private:
	Vector Center_;
	float Radius_;
};

