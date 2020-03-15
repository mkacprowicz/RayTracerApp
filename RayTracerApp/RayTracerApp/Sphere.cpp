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

int Sphere::Intersection(Ray ray, float& dist, Vector& p)
{
	Vector vec = ray.Origin() - this->Center_;
	float b = (-1.0f) * vec.Dot(ray.Direction());
	float det = (b * b) - (-1.0) * vec.Dot(vec) + this->Radius_;

	int res = 0;

	if (det > 0)
	{
		det = std::sqrtf(det);
		float i1 = b - det;
		float i2 = b + det;

		if (i2 > 0)
		{
			if (i1 < 0)
			{
				if (i2 < dist)
				{
					dist = i2;
					res = 2;
				}
			}
			else
			{
				if (i1 < dist)
				{
					dist = i1;
					res = 1;
				}
			}
		}
	}

	Vector hitPoint;

	hitPoint = ray.Origin() + dist * ray.Direction();

	p = hitPoint;

	return res;
}

std::string Sphere::ToString()
{
	return "Sphere(" + this->Center_.ToString() + "," + std::to_string(this->Radius_) + ")";
}
