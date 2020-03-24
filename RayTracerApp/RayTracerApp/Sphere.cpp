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
