#include "OrtoCamera.h"


OrtoCamera::OrtoCamera(Vector origin, Vector lookAt, Vector up, float distance)
{
	this->onb_ = OrthonormalBasis(origin, lookAt, up);
	this->Origin_ = origin;
	this->distance_ = distance;
}

/**
* Function that creates a Ray from a camera. Ray has origin equal to \f$ (0, 0, 50) \f$ .
* @param u - horizontal offset
* @param v - vertical offset
* @return Ray object
*/
Ray OrtoCamera::GetRay(float u, float v)
{
	return Ray(Origin_, RayDirection(u, v));
}

void OrtoCamera::Render()
{
}

Vector OrtoCamera::RayDirection(float u, float v)
{
	return onb_ * Vector(u, v, -distance_);
}
