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

float Sphere::Intersection(Ray ray, Vector& p, float &t) const
{
	Vector vec = ray.Origin() - this->Center_;
	float a = ray.Direction().LenghtSquared();
	float b = 2.0 * vec.Dot(ray.Direction());
	float c = vec.LenghtSquared() - this->Radius_ * this->Radius_;

	float discriminant = b * b - 4 * a * c;

	float res = 0;

	if (discriminant < 0)
	{
		res = 0;
		return res;
	}


	float discSq = std::sqrtf(discriminant);

	float denom = 2 * a;

	t = (-b - discSq) / denom;
	
	const Vector hitPoint = ray.Origin() + t * ray.Direction();
	p = hitPoint;

	return t;
}

bool Sphere::Intersection(Ray ray) const
{
	Vector vec = ray.Origin() - this->Center_;
	float a = ray.Direction().LenghtSquared();
	float b = 2.0 * vec.Dot(ray.Direction());
	float c = vec.LenghtSquared() - this->Radius_ * this->Radius_;

	float discriminant = b * b - 4 * a * c;

	float t;

	if (discriminant < 0)
	{
		return false;
	}

	float discSq = std::sqrtf(discriminant);

	float denom = 2 * a;

	t = (-b - discSq) / denom;

	//const Vector hitPoint = ray.Origin() + t * ray.Direction();
	//p = hitPoint;

	if (t != 0)
	{
		return true;
	}

	return false;
}

bool Sphere::IntersectionB(Ray ray) const		//Ray Tracing in weekend intersection implementation
{
	Vector oc = ray.Origin() - this->Center_;

	float a = ray.Direction().Dot(ray.Direction());
	float b = 2.0 * oc.Dot(ray.Direction());
	float c = oc.Dot(oc) - this->Radius_ * this->Radius_;

	float discriminant = b * b - 4 * a * c;

	return (discriminant > 0);
}

std::ostream& operator<<(std::ostream& os, const Sphere& sph)
{
	os << "Sphere(" << sph.Center_ << "," << std::to_string(sph.Radius_) << ")";
	return os;
}
