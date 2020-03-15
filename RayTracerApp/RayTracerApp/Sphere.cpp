#include "Sphere.h"

Sphere::Sphere()
{
	this->Center_ = Vector::Zero();
	this->Radius_ = 1.0f;
}

Sphere::Sphere(float r)
{
	this->Center_ = Vector::Zero();
	this->Radius_ = r;
}

Sphere::Sphere(Vector v)
{
	this->Center_ = v;
	this->Radius_ = 1.0f;
}

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

std::ostream& operator<<(std::ostream& os, const Sphere& sph)
{
	os << "Sphere(" << sph.Center_ << "," << std::to_string(sph.Radius_) << ")";
	return os;
}
