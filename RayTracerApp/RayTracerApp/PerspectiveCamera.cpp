#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(Vector origin, Vector lookAt, Vector up, float distance)
{
	this->Onb_ = OrthonormalBasis(origin, lookAt, up);
	this->Origin_ = origin;
	this->Distance_ = distance;
}

/**
* Function that creates a Ray from a camera. Ray has origin equal to \f$ (0, 0, 50) \f$ .
* @param uv - horizontal and vertical offset
* @return Ray object
*/
Ray PerspectiveCamera::GetRay(Vector2 uv)
{
	return Ray(this->Origin_, RayDirection(uv));
}

Vector PerspectiveCamera::RayDirection(Vector2 v)
{
	return this->Onb_ * Vector(v.X(), v.Y(), (-1) * this->Distance_);
}
