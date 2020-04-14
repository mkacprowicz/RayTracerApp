#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(Vector origin, Vector lookAt, Vector up, float distance)
{
	this->Onb_ = OrthonormalBasis(origin, lookAt, up);
	this->Origin_ = origin;
	this->Distance_ = distance;
}

/**
* In perspective projection, we get the effect of reducing objects as their distance from the observer increases. 
* The width of the rear plane of the visual solid is different from the width of the front plane and the visual solid is pyramidal.
* the projection plane distance \f$s\f$ is predetermined; if the distance is greater, the resulting image will be larger and will also be generated after calculations.
* The projection system has a specific center \f$e\f$, which is defined in the center of the uvw coordinate system and set in the uvw database (coordinate system of the projection plane). 
* Ray is calculated using OrthonormalBasis (ONB). Having ONB of the cameras available \f$(u, v, w)\f$, position of the point on the viewplane \f$(x, y)\f$, and distance of the viewplane from the eye \f$(d)\f$, 
* we can easily calculate the direction of the ray coming out of the camera as
* \f[
* dir = xu + yv + dw
* \f]
* @param uv - horizontal and vertical offset
* @return Ray object
*/
Ray PerspectiveCamera::GetRay(Vector2 uv)
{
	return Ray(this->Origin_, RayDirection(uv));
}

/**
* Method that calculates direction of camera Ray
* @param v - vertical offset
* @return Vector object - direction of a Ray
*/
Vector PerspectiveCamera::RayDirection(Vector2 v)
{
	return this->Onb_ * Vector(v.X(), v.Y(), (-1) * this->Distance_);
}
