#pragma once
#include "pch.h"
#include "Vector.h"

//! Ray class which is a representation of a ray function
/**
* The <code>Ray</code> class represents a path that the light travels in a virtual scene. To find an object that ray intersects with we have to 
* determine the ray function: \f[ p(t) = A + t*B \f] 
* where p is a 3D position along a line in 3D. A is the ray origin, B is the ray direction and
* the ray parameter t is a real number. Depending on the t point p(t) moves along the ray. For example for t=2 and t=0 the ray funtions would be:
* \f[ 
*	p(2) = A + 2*B,  \\
*	p(0) = A + 0*B => p(0) = A
* \f]
*/

static const float Epsilon = 0.00001f;
static const float Huge = std::numeric_limits<float>::max();

class Ray
{
public:
	Ray();
	Ray(Vector origin, Vector direction);
	Ray(Vector origin, float dis);
	Ray(Vector origin, Vector direction, float dis);

	Vector Origin() const { return Origin_; }
	void Origin(Vector o) { Origin_ = o; }
	Vector Direction() const { return Direction_; }
	void Direction(Vector d) { Direction_ = d; }
	float Distance() const { return Distance_; }
	void Distance(float d) { Distance_ = d; }

	friend std::ostream& operator<<(std::ostream& os, const Ray& ray);

private:
	Vector Origin_;
	Vector Direction_;
	float Distance_;
};

