#include "Ray.h"

Ray::Ray()
{
	this->Origin_ = Vector::Zero();
	this->Direction_ = Vector::Zero();
	this->Distance_ = 0.0f;
}

Ray::Ray(Vector o, Vector d)
{
	this->Origin_ = o;
	this->Direction_ = d;
}
