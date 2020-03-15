#include "Ray.h"

Ray::Ray()
{
	this->Origin_ = Vector::Zero();
	this->Direction_ = Vector::Zero();
	this->Distance_ = 0.0f;
}

Ray::Ray(Vector origin, Vector direction)
{
	this->Origin_ = origin;
	this->Direction_ = direction;
}

Ray::Ray(Vector origin, float dis)
{
	this->Origin_ = origin;
	this->Distance_ = dis;
}

Ray::Ray(Vector origin, Vector direction, float dis)
{
	this->Origin_ = origin;
	this->Direction_ = direction;
	this->Distance_ = dis;
}

std::ostream& operator<<(std::ostream& os, const Ray& ray)
{
	os << "Ray(" << ray.Origin_ << "," << ray.Direction_ << "," << ray.Destination_ << "," << std::to_string(ray.Distance_) << ")";
	return os;
}
