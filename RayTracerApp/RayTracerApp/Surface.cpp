#include "Surface.h"

Surface::Surface()
{
	this->Normal_ = Vector::Zero();
	this->Point_ = Vector::Zero();
}

Surface::Surface(Vector nor, Vector poi)
{
	this->Normal_ = nor;
	this->Point_ = poi;
}

float Surface::GetAngleBetweenNormalAndVector(Vector vec)
{
	float dot = this->Normal_.Dot(vec);
	float lenV1 = this->Normal_.LenghtSquared();
	float lenV2 = vec.LenghtSquared();
	float angleR = std::acos(dot / std::sqrtf(lenV1 * lenV2));

	float angleD = angleR * (180 / M_PI);

	return angleD;
}

bool Surface::Intersection(Ray ray, float& dist, Vector& point)
{
	float denom = ray.Direction().Dot(this->Normal_);

	if (std::abs(denom) < 1e-6)
	{
		return false;
	}
	/*else if (dist <= 0)
	{
		return false;
	}*/
	else
	{
		dist = (this->Point_ - ray.Origin()).Dot(this->Normal_) / denom;
	}


	Vector hitPoint;
	hitPoint = ray.Origin() + dist * ray.Direction();
	point = hitPoint;

	return dist >= 0;
}
