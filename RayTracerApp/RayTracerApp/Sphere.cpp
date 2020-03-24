#include "Sphere.h"

/**
* Default constructor. Creates a sphere object that has center in \f$ (0,0,0) \f$ and radius equal to \f$ 1 \f$
* @return Sphere object
*/
Sphere::Sphere()
{
	this->Center_ = Vector::Zero();
	this->Radius_ = 1.0f;
}

/**
* Basic constructor. Creates a sphere object that has center in \f$ (0,0,0) \f$ and radius equal to \f$ r \f$
* @param r - radius of a sphere
* @return Sphere object
*/
Sphere::Sphere(float r)
{
	this->Center_ = Vector::Zero();
	this->Radius_ = r;
}

/**
* Basic constructor. Creates a sphere object that has center in \f$ v \f$ and radius equal to \f$ 1 \f$
* @param v - center of a sphere
* @return Sphere object
*/
Sphere::Sphere(Vector v)
{
	this->Center_ = v;
	this->Radius_ = 1.0f;
}

/**
* Basic constructor. Creates a sphere object that has center in \f$ v \f$ and radius equal to \f$ r \f$
* @param r - radius of a sphere
* @param v - center of a sphere
* @return Sphere object
*/
Sphere::Sphere(Vector v, float r)
{
	this->Center_ = v;
	this->Radius_ = r;
}

/**
* Function that checks whether or not Sphere intersects with a Ray. There are three possible cases that can occur:
*	- Ray doesn't hit a Sphere
*	- Ray hits a Sphere in one point
*	- Ray hits a Sphere in two points
* To examine which case is valid we have to determine an equation:
* \f[
* ||A + Bt -c||^2 = r^2 <=> (A + Bt - c) \cdot (A + Bt - c) = r^2 \\
*	t^2(B \cdot B) + 2t(B \cdot (A - c)) + (A - c) \cdot (A - c) = r^2 \\
*	t^2(B \cdot B) + 2t(B \cdot (A - c)) + (A - c) \cdot (A - c) - r^2 = 0 \\
* \f]
* which is equal to quadratic equation:
* \f[
*	at^2 + bt + c = 0
* \f]
* where:
* \f[
*	a = B \cdot B = ||B||^2 \\
*	b = 2(B \cdot (A - c)) \\
*	c = (A - c) \cdot (A - c) - r^2 = ||A - c||^2 - r^2
* \f] 
* what can be simplified:
* \f[
* t = \frac{-2(B \cdot (A - c)) \pm \sqrt{(2(B \cdot (A - c)))^2 - 4||B||^2 (||A - c||^2 - r^2)}}{2||B||} \\
* ||A||^2 = 1, so \\
* t = -(B * (A - c)) \pm \sqrt{(B \cdot (A - c))^2 - ||A - c||^2 + r^2)} 
* \f]
*	- if the sqrt value \f$ (B \cdot (A - c))^2 - ||A - c||^2 + r^2) < 0\f$ equation cannot be solved, thus Ray is not intersecting with a Sphere 
*	- if it's equal to \f$ 0 \f$ there is only one solution - the Ray intersects with a Sphere in one spot
*	- if it's more than zero the Ray intersects with the Spehere in two spots
* @param ray - radius of a sphere
* @param t_min - minimal length of a ray cast (it's starting point)
* @param t_max - maximal length of a ray cast (it's end point)
* @return Bool - tells us whether it intersects or not
*/
bool Sphere::Hit(Ray ray, float t_min, float t_max) const
{
	Vector oc = ray.Origin() - this->Center_;

	float a = ray.Direction().Dot(ray.Direction());
	float b = oc.Dot(ray.Direction());
	float c = oc.Dot(oc) - this->Radius_ * this->Radius_;

	float discriminant = b * b - a * c;

	if (discriminant > 0)
	{
		float temp = (-b - std::sqrtf(discriminant)) / a;

		if (temp < t_max && temp > t_min)
		{
			return true;
		}

		temp = (-b + std::sqrtf(discriminant)) / a;

		if (temp < t_max && temp > t_min)
		{
			return true;
		}
	}

	return false;
}

std::ostream& operator<<(std::ostream& os, const Sphere& sph)
{
	os << "Sphere(" << sph.Center_ << "," << std::to_string(sph.Radius_) << ")";
	return os;
}
